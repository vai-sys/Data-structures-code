class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int count=0;
        int ans=0;
        for(int bitpos=0;bitpos<32;bitpos++){
            count=0;
            for(int nums:candidates){
                if(nums & (1<<bitpos)){
                    count++;
                }
            }
            ans=max(count,ans);

        }
        return ans;
    }
};