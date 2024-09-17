class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        vector<string> ans;

       
        auto processSentence = [&](const string& sentence) {
            istringstream iss(sentence);
            string word;
            while (iss >> word) {
                mp[word]++;
            }
        };

        
        processSentence(s1);
        processSentence(s2);

       
        for (const auto& pair : mp) {
            if (pair.second == 1) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};