class Solution {
private:
    vector<string> split(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }

public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1.length() < s2.length()) {
            swap(s1, s2);
        }

        vector<string> vec1 = split(s1);
        vector<string> vec2 = split(s2);

        int i = 0;
        int j = vec1.size() - 1;
        int k = 0;
        int l = vec2.size() - 1;

        while (i < vec1.size() && k < vec2.size() && vec1[i] == vec2[k]) {
            i++;
            k++;
        }

        while (l >= k && vec1[j] == vec2[l]) {
            j--;
            l--;
        }

        return l < k;
    }
};
