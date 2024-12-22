class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        while (true) {
           
            unordered_set<int> unique(nums.begin(), nums.end());
            if (unique.size() == nums.size()) {
                break;
            }

            count++;
            if (nums.size() <= 3) {
                nums.clear();
            } else {
                nums.erase(nums.begin(), nums.begin() + 3); 
            }
        }
        
        return count;
    }
};
