class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>seen;
        return backtrack(0,s,seen);
    }


 private:
     int backtrack(int start,string& s,unordered_set<string>& seen){
        if(start==s.length()){
            return 0;
        }
           int maxCnt=0;
        for(int end=start+1;end<=s.length();end++){
            string subs=s.substr(start,end-start);
            if(seen.find(subs)==seen.end()){
                seen.insert(subs);
                maxCnt=max(maxCnt,1+backtrack(end,s,seen));
                seen.erase(subs);
            }

        }
        return maxCnt;
     }   
};