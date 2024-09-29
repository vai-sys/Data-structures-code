class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";  
        while (word.length() < k) {
            string newPart = "";
          
            for (char c : word) {
                char nextChar = (c == 'z') ? 'a' : c + 1;  
                newPart += nextChar;
            }
            word += newPart;  
        }
        
      
        return word[k - 1];  
    }
};
