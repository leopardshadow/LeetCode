/*
    write a function of counting 1s
*/

int count1(int n) {
    int cnt = 0;
    while(n) {
        n = n & (n-1);
        cnt++;
    }   
    return cnt;
}

int* countBits(int n, int* returnSize){

    int *arr = malloc(sizeof(int) * (n+1));
    *returnSize = n + 1;
    for(int i = 0; i <= n; i++) {
        arr[i] = count1(i);
    }
    return arr;
}

/*
Runtime: 57 ms, faster than 35.55% of C online submissions for Counting Bits.
Memory Usage: 10.6 MB, less than 17.69% of C online submissions for Counting Bits.
*/