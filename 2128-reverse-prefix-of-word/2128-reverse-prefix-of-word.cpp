class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t index = word.find(ch);

         int start=0;
         int end=index;
         while(start<end){
            swap(word[start],word[end]);
            start++;
            end--;
         }
         return word;
    }
};