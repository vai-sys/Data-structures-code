class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<intervals.size();i++){
           int left=intervals[i][0];
           int right=intervals[i][1];
           if(!pq.empty() && left >pq.top()){
            pq.pop();
           }
           pq.push(right);
        }
        return pq.size();
    }
};