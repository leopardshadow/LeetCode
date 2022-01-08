
// 2022.1.8

/*
覺得這題麻煩的點是：如果兩個 robot 都經過同一個 cell，則只會拿一個
如果可以兩個人都加 grid[i][j]，那就只要分開處理就好
---
原本我希望兩個 robot 各自存自己的 cherry 數量，但這樣會遇到一個問題：如果有重疊，數量應該要加在誰身上，因為我們最後只會回傳總和，所以計算總和應該要合併考慮，綜合考慮 states
*/

class Solution {
    
    int dp[71][71][71];
    int r, c;
    
    int solve(int i, int j1, int j2, vector<vector<int>>& grid) {
        
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
            return 0;
        
        else if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
           
        int res = 0;
        
        if(i != r - 1) {
            for(int jj1 = j1 - 1; jj1 <= j1 + 1; jj1++) {
                for(int jj2 = j2 - 1; jj2 <= j2 + 1; jj2++) {
                    res = max(res, solve(i+1, jj1, jj2, grid));
                }
            }
        }
        
        if(j1 != j2)
            res += (grid[i][j1] + grid[i][j2]);
        else
            res += grid[i][j1];

        dp[i][j1][j2] = res;
        return res;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        for(int i = 0; i < 71; i++)
            for(int j = 0; j < 71; j++)
                for(int k = 0; k < 71; k++)
                    dp[i][j][k] = -1;
        
        return solve(0, 0, c-1, grid);        
    }
};

/*
Runtime: 63 ms, faster than 45.16% of C++ online submissions for Cherry Pickup II.
Memory Usage: 9.9 MB, less than 75.00% of C++ online submissions for Cherry Pickup II.
*/


//******************************************************************************//
// 想嘗試 iterative 寫法的屍體
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int R = grid.size(),
            C = grid[0].size();
        
        vector<vector<int>> dp0(C, vector<int>(C, 0));
        vector<vector<int>> dp1(C, vector<int>(C, 0));
        
        
        int ans = 0;
        
        vector<vector<int>> &prev = dp0;
        vector<vector<int>> &curr = dp1;
        
        prev[0][C-1] = grid[0][0] + grid[0][C-1];
            
        for(int r = 1; r < R; r++) {
                
            for(int c1 = 0; c1 < C; c1++) {
                for(int c2 = 0; c2 < C; c2++) {
                    
                    curr[c1][c2] = max({
                        c1 - 1 >= 0 ? prev[c1-1][c2] : 0,
                        c1 + 1 < C ? prev[c1+1][c2] : 0,
                        c1 - 1 >= 0 ? prev[c1]
                    });
                }
            }

            prev = (r % 2 == 0 ? dp0 : dp1);
            curr = (r % 2 == 0 ? dp1 : dp0);
        }
        
        return ans;
    }
};
