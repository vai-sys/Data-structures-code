class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int k=0;
        
        int ele1=-1;
        int ele2=-1;
        int n=nums1.size()+nums2.size();
        
        
        int idx1 = (n - 1) / 2;  
        int idx2 = n / 2;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                if(k == idx1){
                    ele1 = nums1[i];
                }
                if(k == idx2){
                    ele2 = nums1[i];
                }
                i++;
            }
            else{
                if(k == idx1){
                    ele1 = nums2[j];
                }
                if(k == idx2){
                    ele2 = nums2[j];
                }
                j++;
            }
            k++;  
        }

     
        while(i < nums1.size()){
            if(k == idx1){
                ele1 = nums1[i];
            }
            if(k == idx2){
                ele2 = nums1[i];
            }
            i++;
            k++;
        }

        while(j < nums2.size()){
            if(k == idx1){
                ele1 = nums2[j];
            }
            if(k == idx2){
                ele2 = nums2[j];
            }
            j++;
            k++;
        }

        
        if(n % 2 == 0){
            return (ele1 + ele2) / 2.0;
        }
        else{
            return ele2;
        }
    }
};
