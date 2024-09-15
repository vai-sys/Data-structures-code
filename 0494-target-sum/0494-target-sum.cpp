class Solution {
public:
    int solve( vector<int>& nums,int target,int index,int curr_sum){

        if(index<0 && curr_sum==target){
            return 1;

        }
        if(index<0)return 0;
        int pos=solve(nums,target,index-1,curr_sum+nums[index]);
        int neg=solve(nums,target,index-1,curr_sum-nums[index]);
        return neg+pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int curr_sum=0;
        return solve(nums,target,nums.size()-1,0);
    }
};