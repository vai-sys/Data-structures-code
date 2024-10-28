class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        unordered_map<int, int> mp;
        int result = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int root = sqrt(nums[i]);
            if (mp.find(root) != mp.end() && root * root == nums[i]) { 
                mp[nums[i]] = 1 + mp[root];
                result = max(result, mp[nums[i]]);
            } else {
                mp[nums[i]] = 1;
            }
        }

        return result==0 ? -1 :result;
    }
};