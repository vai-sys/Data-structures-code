class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans="";
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;


        for(auto pair:mp){
            int count=pair.second;
            int ch=pair.first;
            pq.push({count,ch});
        }
    
        while(!pq.empty()){
            int cnt=pq.top().first;
            int str=pq.top().second;
            pq.pop();
            ans.append(cnt,str);
        }
        return ans;
        
    }
};