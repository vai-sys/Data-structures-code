class Solution {
public:
     void dfs(int sr,int sc,vector<vector<int>>& image,int color,int originColor){    
            if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return; 
        if(image[sr][sc]!=originColor){
            return;
        }
        if(image[sr][sc]==color)return;

        image[sr][sc]=color;
        dfs(sr+1,sc,image,color,originColor);
        dfs(sr-1,sc,image,color,originColor);
        dfs(sr,sc+1,image,color,originColor);
        dfs(sr,sc-1,image,color,originColor);

     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int originColor=image[sr][sc];
        if(originColor != color){
            dfs(sr,sc,image,color,originColor);
        }
        return image;
        
    }
};