class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& memo) {
       
        if (memo[row][col] != -1) {
            return memo[row][col];
        }
        
        int n = grid.size();
        int m = grid[0].size();
        int moves = 0;

        // Directions: up-right, right, down-right
        vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
        
        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < n && newCol < m && grid[newRow][newCol] > grid[row][col]) {
                moves = max(moves, 1 + dfs(newRow, newCol, grid, memo));
            }
        }
        
        memo[row][col] = moves;
        return moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int result = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1)); 
        for (int row = 0; row < n; row++) {
            result = max(result, dfs(row, 0, grid, memo));
        }
        
        return result;
    }
};
