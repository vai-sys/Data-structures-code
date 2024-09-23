class Solution {
public:
    unordered_set<string> st;  
    
    int solve(int idx, string& s, vector<int>& dp) {
        int n = s.length();
        if (idx >= n) return 0;  
        if (dp[idx] != -1) return dp[idx];  
        
        string curString = "";
        int minExtra = n;  
        for (int i = idx; i < n; i++) {
            curString.push_back(s[i]);
            
            int curExtra;
            if (st.find(curString) == st.end()) {
                
                curExtra = curString.length();
            } else {
              
                curExtra = 0;
            }
            
           
            int nextExtra = solve(i + 1, s, dp);
            
            minExtra = min(minExtra, curExtra + nextExtra);
        }
        
        return dp[idx] = minExtra;  
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
      
        for (auto& word : dictionary) {
            st.insert(word);
        }
      
        vector<int> dp(s.length(), -1);
        
        return solve(0, s, dp);
    }
};
