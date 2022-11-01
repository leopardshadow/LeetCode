
// 2022.11.1

/*
討厭這種題目，麻煩的不是演算法，而是他的表示法。。。
*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> flow(m, vector<int>(n, 0));
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1 && c < n-1 && grid[r][c+1] == 1)
                    flow[r][c] = 1;
                if (grid[r][c] == -1 && c >= 1 && grid[r][c-1] == -1)
                    flow[r][c] = -1;
            }
        }
                
        vector<int> ans(n, -1);
                
        for (int c = 0; c < n; c++) {
            int i = c;
            bool early_stop = false;
            for (int r = 0; r < m; r++) {
                if (!flow[r][i]) {
                    early_stop = true;
                    break;
                }
                i += flow[r][i];
            }
            if (!early_stop)
                ans[c] = i;
        }
        
        return ans;
    }
};
/*
Runtime: 60 ms, faster than 38.07% of C++ online submissions for Where Will the Ball Fall.
Memory Usage: 14.2 MB, less than 8.82% of C++ online submissions for Where Will the Ball Fall.
*/
