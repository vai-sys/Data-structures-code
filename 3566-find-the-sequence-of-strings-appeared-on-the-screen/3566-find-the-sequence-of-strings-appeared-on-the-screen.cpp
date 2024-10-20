class Solution {
public:
    vector<string> stringSequence(string target) {
        int i = 0;
        string ans = "";
        vector<string> res;
        
        while (i < target.length()) {
          
            ans += 'a';
            res.push_back(ans); 
            
            
            while (ans[i] != target[i]) {
                ans[i] = (ans[i] - 'a' + 1) % 26 + 'a';  
                res.push_back(ans); 
            }
            
            i++; 
        }
        
        return res;
    }
};
