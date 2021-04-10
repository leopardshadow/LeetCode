#include <stdio.h>

void rotate(int** matrix, int matrixRowSize, int* matrixColSize){
    int tmp;
    int n = matrixRowSize;
    for(int i = 0; i < (n+1)/2; i++) {
        for(int j = 0; j < n / 2; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}

void print(int** matrix, int n) {

    /**
        Note. 
        https://www.ptt.cc/bbs/C_and_CPP/M.1465304337.A.9F2.html
        12. 不要猜想二維陣列可以用 pointer to pointer 來傳遞
    **/

    printf("%d", *(matrix+0)[0]);
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
}

int main(int argc, char const *argv[])
{
    int matrix[4][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};   
    print(matrix, 4);
    // rotate(matrix, 4, *matrix[0]);

    return 0;
}
