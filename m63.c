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
    
    int **table = malloc(sizeof(int*) * obstacleGridSize);
    for(int i = 0; i < obstacleGridSize; i++)
        table[i] = malloc(sizeof(int) * (*obstacleGridColSize));

    // 
    bool stuck = false;
    for(int r = 0; r < obstacleGridSize; r++) {
        if(stuck) {
            table[r][0] = 0;
        }
        else if(obstacleGrid[r][0]) {
            stuck = true;
            table[r][0] = 0;
        }
        else {
            table[r][0] = 1; 
        }
    }
    
    // 
    stuck = false;
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

    
    
    for(int r = 1; r < obstacleGridSize; r++) {
        for(int c = 1; c < *obstacleGridColSize; c++) {
            
            if(!obstacleGrid[r][c])
                table[r][c] = table[r-1][c] + table[r][c-1];
            else table[r][c] = 0;
        }
    }
    
    ans = table[obstacleGridSize-1][*obstacleGridColSize-1];
    
    
    for(int i = 0; i < obstacleGridSize; i++)
        free(table[i]);
    free(table);
    
    return ans;
    
}


/*
Runtime: 4 ms, faster than 70.65% of C online submissions for Unique Paths II.
Memory Usage: 6.2 MB, less than 44.57% of C online submissions for Unique Paths II.
*/