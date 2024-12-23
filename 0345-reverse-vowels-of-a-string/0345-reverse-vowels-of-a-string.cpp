class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1; 
        auto isVowel = [](char c) {
            c = tolower(c); 
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        while (i < j) {
            if (isVowel(s[i]) && isVowel(s[j])) { 
                swap(s[i], s[j]); 
                i++;
                j--;
            } else if (!isVowel(s[i])) { 
                i++; 
            } else { 
                j--; 
            }
        }
        return s;
    }
};
