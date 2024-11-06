class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                int bit1 = countSetBits(nums[j]);
                int bit2 = countSetBits(nums[j + 1]);

                if (bit1 == bit2 && nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }

      for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }

        return true;  

    }
    };