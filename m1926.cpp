
// 2022.11.21

/*
BFS
*/

class Solution {
    int dx[4] = {0,  0, 1, -1};
    int dy[4] = {1, -1, 0,  0};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> steps(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        steps[entrance[0]][entrance[1]] = 0;
        int ans = INT_MAX;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                if (x != entrance[0] || y != entrance[1])
                    ans = min(ans, steps[x][y]);
            }
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n || maze[nx][ny] == '+' ||
                     steps[nx][ny] >= 0)
                    continue;
                else {
                    q.push({nx, ny});
                    steps[nx][ny] = steps[x][y] + 1;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
Runtime: 206 ms, faster than 77.92% of C++ online submissions for Nearest Exit from Entrance in Maze.
Memory Usage: 35.1 MB, less than 29.14% of C++ online submissions for Nearest Exit from Entrance in Maze.
*/
