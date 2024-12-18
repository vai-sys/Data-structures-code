class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> arrJ;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                arrJ.push_back(i);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < arrJ.size(); j++) {
                if (abs(i - arrJ[j]) <= k) {
                    result.push_back(i);
                    break; 
                }
            }
        }

        return result;
    }
};
