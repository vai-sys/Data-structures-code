class Solution {
public:
    int solve(vector<int>& nums, int idx ,int maxOr,int currOr){
        if(idx==nums.size()){
            if(maxOr==currOr){
                return 1;
            }
            else{
                return 0;
            }
        }

     int include=solve(nums,idx+1,maxOr,currOr | nums[idx]);
     int notInclude=solve(nums,idx+1,maxOr ,currOr);
     return include + notInclude;


    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
      for(int i=0;i<nums.size();i++){
           maxOr |=nums[i];
      }
      int currOr=0;
      int idx=0;
      return solve(nums,idx,maxOr,currOr);
    }
};