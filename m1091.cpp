
// 2022.5.16

/*
BFS
---
像這種走迷宮的題目都要特別注意起點、終點能不能走，如果一開始起點就是牆就不用走了
*/

class Solution {
    
    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        vector<vector<int>> steps(grid.size(), vector<int>(grid[0].size(), -1));
        queue<pair<int, int>> q;
        
        if (grid[0][0] == 0) {
            steps[0][0] = 1;
            q.push({0, 0});
        }
        
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || 
                    grid[nx][ny] == 1 || 
                    steps[nx][ny] > 0)
                    continue;
                else {
                    steps[nx][ny] = steps[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return steps.back().back();
    }
};
/*
Runtime: 69 ms, faster than 80.61% of C++ online submissions for Shortest Path in Binary Matrix.
Memory Usage: 20.7 MB, less than 52.13% of C++ online submissions for Shortest Path in Binary Matrix.
*/
