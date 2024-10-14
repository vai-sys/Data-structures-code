class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshCnt = 0;
        int minute = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCnt++;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty() && freshCnt > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto rotten = q.front();
                q.pop();

                int x = rotten.first;
                int y = rotten.second;

                for (auto dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        freshCnt--;
                    }
                }
            }
            minute++;
        }

        if (freshCnt > 0) return -1;
        return minute;
    }
};
