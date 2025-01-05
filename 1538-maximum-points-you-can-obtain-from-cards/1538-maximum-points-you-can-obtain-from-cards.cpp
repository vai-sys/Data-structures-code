class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

     int rsum=0;
     int maxSum=0;
     int lsum=0;
     for(int i=0;i<k;i++){
        lsum+=cardPoints[i];
    

     }
         maxSum=lsum;

     int n=cardPoints.size();

     int rightIdx=n-1;
     for(int i=k-1;i>=0;i--){
        lsum-=cardPoints[i];
        rsum+=cardPoints[rightIdx];
        rightIdx--;
        maxSum=max(maxSum,lsum+rsum);

     }
     return maxSum;

        
    }
};