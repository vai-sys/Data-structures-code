

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
      
        if (n > m) return false;
        
     
        vector<int> s1Freq(26, 0), s2Freq(26, 0);
        
        // Initialize the frequency arrays for s1 and the first window in s2
        for (int i = 0; i < n; i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }
        
        // Compare the frequency arrays for the first window
        if (s1Freq == s2Freq) return true;
        
        // Slide the window across s2
        for (int i = n; i < m; i++) {
            // Include the new character in the window
            s2Freq[s2[i] - 'a']++;
            // Remove the character that's out of the window
            s2Freq[s2[i - n] - 'a']--;
            
            // Check if the current window matches the frequency of s1
            if (s1Freq == s2Freq) return true;
        }
        
        return false;
    }
};
