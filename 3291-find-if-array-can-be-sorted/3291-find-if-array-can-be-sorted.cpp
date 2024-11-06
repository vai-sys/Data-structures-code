



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
    bool swapped;


    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            int setBits1 = countSetBits(nums[i]);
            int setBits2 = countSetBits(nums[i + 1]);

           
            if (setBits1 == setBits2 && nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);

    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }

    return true;
}

};