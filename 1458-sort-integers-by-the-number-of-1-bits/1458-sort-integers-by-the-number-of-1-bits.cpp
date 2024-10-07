class Solution {
public:
    int countBit(int n){
        int count=0;
        while(n){
            count+=n&1;
            n>>=1;

        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda=[&](int &a,int &b){
            int cA=countBit(a);
            int cB=countBit(b);
            if(cA==cB){
                return a<b;
            }
            return cA < cB;
        };

        sort(arr.begin(),arr.end(),lambda);
        return arr;
        
    }
};