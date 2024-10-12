class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,int u,vector<bool>&vis){
        vis[u]=true;
        for(int &V:mp[u]){
            if(!vis[V]){
                dfs(mp,V,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>mp;
        int n=isConnected.size();
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
          int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(mp,i,vis);
                 count++;
            }
           
        }

    return count;
    }
};