class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int ans=INT_MAX;
        bool found=false;

        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                int length=j-i+1;
                sum+=nums[j];
                if(length>=l && length<=r && sum>0){
                    ans=min(ans,sum);
                    found=true;
                }
            }
        }

            
return found?ans:-1; 

        
    }
};