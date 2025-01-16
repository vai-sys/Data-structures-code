class Solution {
private:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      
       long long val = m * 1ll * k * 1ll;
       int n = bloomDay.size();
    if (val > n) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            mini = min(bloomDay[i], mini);
            maxi = max(bloomDay[i], maxi);
        }

        int low = mini;
        int high = maxi;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};
