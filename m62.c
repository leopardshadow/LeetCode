
int uniquePaths(int m, int n){
    int mm = m < n ? m : n; // min m n
    int nn = m >= n ? m : n; // max m n
    int **table = malloc(sizeof(int*) * mm);
    for(int i = 0; i < mm; i++)
        table[i] = malloc(sizeof(int) * nn);
    
    for(int i = 0; i < mm; i++)
        table[i][0] = 1;
    
    for(int c = 1; c < nn; c++) {
        table[0][c%2] = 1;
        for(int r = 1; r < mm; r++) {
            table[r][c%2] = table[r][(c-1)%2] + table[r-1][c%2];
        }
    }
    return table[mm-1][(nn-1)%2];
}

/*
Runtime: 2 ms, faster than 25.99% of C online submissions for Unique Paths.
Memory Usage: 5.8 MB, less than 17.18% of C online submissions for Unique Paths.
*/