
// 2022.7.15

/*
就 BFS~
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dx[4] = {0, 1,  0, -1};
        int dy[4] = {1, 0, -1,  0};

        int ans = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] == 1) {
                    
                    queue<pair<int, int>> q;
                    int island = 0;

                    q.push({i, j});
                    grid[i][j] = 0;
                    island++;

                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d], ny = y + dy[d];
                            if (nx >= 0 && nx < m &&
                                ny >= 0 && ny < n &&
                                grid[nx][ny]) {
                                q.push({nx, ny});
                                grid[nx][ny] = 0;
                                island++;

                            }
                        }
                    }
                    ans = max(ans, island);
                }
            }
        }
        
        return ans;
    }
};
/*
Runtime: 20 ms, faster than 86.81% of C++ online submissions for Max Area of Island.
Memory Usage: 26.8 MB, less than 15.50% of C++ online submissions for Max Area of Island.
*/
