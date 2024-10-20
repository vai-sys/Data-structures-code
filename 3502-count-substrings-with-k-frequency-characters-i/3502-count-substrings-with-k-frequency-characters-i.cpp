





class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int result = 0;
        
        for (int left = 0; left < n; ++left) {
            unordered_map<char, int> freqMap;
            for (int right = left; right < n; ++right) {
                freqMap[s[right]]++;
                
                bool valid = false;
                for (auto& entry : freqMap) {
                    if (entry.second >= k) {
                        valid = true;
                        break;
                    }
                }
                
                if (valid) {
                    result++;
                }
            }
        }
        
        return result;
    }
};
