class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int maxPair=0;
        while(start <=end){
            int sum=nums[start]+nums[end];
            maxPair=max(maxPair,sum);
            start++;
            end--;

        }
        return maxPair;
    }
};