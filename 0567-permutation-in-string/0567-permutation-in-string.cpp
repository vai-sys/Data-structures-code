class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n=s1.length();
        int m=s2.length();
        if(n>m) return false;
        sort(s1.begin(),s1.end());
        for(int i=0;i<m;i++){
            string str=s2.substr(i,n);
            sort(str.begin(),str.end());
            if(str==s1){
                return true;
            }

        }
        return false;







    }
};