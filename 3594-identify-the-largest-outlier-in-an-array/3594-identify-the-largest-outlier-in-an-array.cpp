class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int totalSum = 0;
        unordered_map<int, int> freq;

        for (int num : nums) {
            totalSum += num;
            freq[num]++;
        }

        int largestOutlier = INT_MIN;

        for (int num : nums) {
            int remainingSum = totalSum - num;

            if (remainingSum % 2 == 0) {
                int possibleSum = remainingSum / 2;

                
                if (freq[possibleSum] > (possibleSum == num ? 1 : 0)) {
                    largestOutlier = max(largestOutlier, num);
                }
            }
        }

        return largestOutlier;
    }
};