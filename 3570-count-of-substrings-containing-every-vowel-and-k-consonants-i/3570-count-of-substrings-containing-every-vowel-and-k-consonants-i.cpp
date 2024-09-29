


class Solution {
public:
     int countOfSubstrings(string word, int k) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int totalCount = 0;
    int n = word.length();


    for (int start = 0; start < n; ++start) {
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

       
        for (int end = start; end < n; ++end) {
            char c = word[end];

         
            if (vowels.count(c)) {
                vowelCount[c]++;
            } 
         
            else if (isalpha(c)) {
                consonantCount++;
            }

            bool allVowelsPresent = true;
            for (char v : vowels) {
                if (vowelCount[v] == 0) {
                    allVowelsPresent = false;
                    break;
                }
            }

           
            if (allVowelsPresent && consonantCount == k) {
                totalCount++;
            }
        }
    }

    return totalCount;
 }
};