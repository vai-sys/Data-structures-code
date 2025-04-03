class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
       for(int i=0;i<score.size();i++){
        pq.push({score[i],i});
       }

        int cnt=0;
        vector<string>ans(score.size());
        while(!pq.empty()){
          auto top=pq.top();
          pq.pop();
          int idx=top.second;

          cnt++;
          if(cnt==1){
            ans[idx]="Gold Medal";

          }
          else if(cnt==2){
            ans[idx]="Silver Medal";
          }
          else if(cnt==3){
            ans[idx]="Bronze Medal";
          }
          else{
            ans[idx]=to_string(cnt);
          }
        }
        return ans;
    }
};