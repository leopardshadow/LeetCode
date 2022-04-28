
// 2022.4.28

/*
居然真的是 binary search，有大概猜到，但還是先看了一下 hint 才確定
---
好怕這種兩個條件不是三個的 binary search 題
if (search(m))
    r = m  // 因為他不一定能夠縮小還維持 true
else
    l = m + 1  // 但一定要變大才有機會到 true
---
***想一下 l = a, r = a + 1 的情況***
情況一：答案是 a
m = a -> if search 為 true -> r = a，跳出迴圈
情況二：答案是 a + 1
m = a -> if search 為 false -> l = a + 1 -> 跳出迴圈
*/

class Solution {
    int m, n;
    int dr[4] = {0, 1,  0, -1};
    int dc[4] = {1, 0, -1,  0};
    bool search(vector<vector<int>>& heights, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int r = p.first, c = p.second;
                int nr = r + dr[d],
                    nc = c + dc[d];
                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc] &&
                    abs(heights[r][c] - heights[nr][nc]) <= k) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return visited[m-1][n-1];  // could return earlier
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        int l = 0, r = 1000000;
        while (l < r) {
            int m = (l + r) / 2;
            if (search(heights, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};

/*
Runtime: 382 ms, faster than 42.68% of C++ online submissions for Path With Minimum Effort.
Memory Usage: 50.6 MB, less than 27.84% of C++ online submissions for Path With Minimum Effort.
*/
