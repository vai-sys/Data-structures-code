class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            bool found = false;
            for (int x = 0; x <= nums[i]; x++) {
                if ((x | (x + 1)) == nums[i]) {
                    ans[i] = x;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};
