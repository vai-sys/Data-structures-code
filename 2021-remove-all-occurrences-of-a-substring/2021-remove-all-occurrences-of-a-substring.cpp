class Solution {
public:
    string solve(string& s, const string& part) {
        int found = s.find(part);
        if (found != string::npos) {
            string left = s.substr(0, found);
            string right = s.substr(found + part.size(), s.size() - (found + part.size()));
            s = left + right;
            solve(s, part);
        }
        return s;
    }

    string removeOccurrences(string s, const string& part) {
        return solve(s, part);
    }
};
