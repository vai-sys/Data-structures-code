class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
    vector<int> result(n); 
    int left = 0;          
    int right = n - 1;     

   
    for (int num : nums) {
        if (num < pivot) {
            result[left++] = num; 
        }
    }
    for (int num : nums) {
        if (num == pivot) {
            result[left++] = num; 
        }
    }
    for (int num : nums) {
        if (num > pivot) {
            result[left++] = num; 
        }
    }

    return result;
}
};





