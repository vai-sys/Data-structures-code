class Solution {
public:
    int maximumSwap(int num) {
        string nums=to_string(num);
        int n=nums.length();
       vector<int>maxElement(n);
       maxElement[n-1]=n-1;

       for(int i=n-2;i>=0;i--){
        int maxIdx=maxElement[i+1];
        int maxE=nums[maxIdx];
        maxElement[i]=nums[i] > maxE ? i:maxIdx;  
       }

       for(int i=0;i<n;i++){
        int maxIdx=maxElement[i];
        int maxE=nums[maxIdx];
        if(nums[i] < maxE){

            swap(nums[i],nums[maxIdx]);
            return stoi(nums);

        }
       }
      
        return num;
    }
};