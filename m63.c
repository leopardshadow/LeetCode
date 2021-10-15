/*
S 0 0
0 1 0
0 0 F

1 1 1
1 0 1
1 1 2
*/

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