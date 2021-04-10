#include <stdio.h>
#include <stdlib.h>

//                                                vvvvv ? vvvvv
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

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    /**
        Note. 
        https://www.ptt.cc/bbs/C_and_CPP/M.1465304337.A.9F2.html
        12. 不要猜想二維陣列可以用 pointer to pointer 來傳遞

        int matrix[4][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};   --> 會出錯
    **/


    int mat[4][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int n = 4;
    int **arr = (int**)malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int)*n);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] = mat[i][j];
        }
    }

    print(arr, n);

    rotate(arr, n, arr[0]);
    printf("\nafter rotation\n----------\n");

    print(arr, n);


    for(int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
