/*
S 0 0
0 1 0
0 0 F

1 1 1
1 0 1
1 1 2
*/

// Be aware of the corner cases,
// if the start is also an obstacle

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){

    int ans = 0;
    
    int **table = malloc(sizeof(int*) * 2);
    for(int i = 0; i < 2; i++)
        table[i] = malloc(sizeof(int) * (*obstacleGridColSize));

    if(obstacleGrid[0][0])
        table[0][0] = 0;
    
    // first row
    bool stuck = obstacleGrid[0][0];
    for(int c = 0; c < *obstacleGridColSize; c++) {
        if(stuck) {
            table[0][c] = 0;
        }
        else if(obstacleGrid[0][c]) {
            stuck = true;
            table[0][c] = 0;
        }
        else {
            table[0][c] = 1; 
        }
    }
    
    // get stuck in the vectical direction
    stuck = obstacleGrid[0][0];
    
    //
    for(int r = 1; r < obstacleGridSize; r++) {

        if(stuck) {
            table[r%2][0] = 0;
        }
        else if(obstacleGrid[r][0]) {
            stuck = true;
            table[r%2][0] = 0;
        }
        else {
            table[r%2][0] = 1; 
        }

        
        for(int c = 1; c < *obstacleGridColSize; c++) {
            if(!obstacleGrid[r][c])
                table[r%2][c] = table[(r-1)%2][c] + table[r%2][c-1];
            else
                table[r%2][c] = 0;
        }
    }
    
    ans = table[(obstacleGridSize-1)%2][*obstacleGridColSize-1];
    
    for(int i = 0; i < 2; i++)
        free(table[i]);
    free(table);
    
    return ans;
}

/*
Runtime: 3 ms, faster than 73.91% of C online submissions for Unique Paths II.
Memory Usage: 6 MB, less than 69.57% of C online submissions for Unique Paths II.
*/



// 2022.5.20

/*
這種走迷宮的題目一定要注意開始和終點不能走的情況
---
上次寫居然是在用 C 的時候，這次改成 C++ 的版本，在判斷條件上也用了更簡潔的寫法
我是先算 X 的部分
X X X X
X _ _ _
X _ _ _ 
以橫的那條來說，cnt[0][j] == cnt[0][j-1] == 1，除非 obstacle[0][j] == 1，且 cnt[0][x] == 0 for x >= j
直的也同理
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        cnt[0][0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
        for (int i = 1; i < n; i++)
            cnt[i][0] = cnt[i-1][0] && (obstacleGrid[i][0] == 0);
        for (int j = 1; j < m; j++)
            cnt[0][j] = cnt[0][j-1] && (obstacleGrid[0][j] == 0);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                cnt[i][j] = obstacleGrid[i][j] == 0 ? (cnt[i-1][j] + cnt[i][j-1]) : 0;
            }
        }
        return cnt[n-1][m-1];
    }
};
/*
Runtime: 3 ms, faster than 80.74% of C++ online submissions for Unique Paths II.
Memory Usage: 7.7 MB, less than 60.56% of C++ online submissions for Unique Paths II.
*/
