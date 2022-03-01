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




python -m grpc_tools.protoc -I../../protos --python_out=. --grpc_python_out=. ../../protos/helloworld.proto


// 2022.3.1

/*
這題之前寫過，但沒注意到有 Follow up 和 Hints =w=
---
把他列出來大概就可以發現規則，後面的數字可以由前面的數字決定
---
 0 - 0
---
 1 - 1
---
 2 - 1 .
 3 - 2 +
---
 4 - 1 .
 5 - 2 .
 6 - 2 +
 7 - 3 +
---
 8 - 1 .
 9 - 2 .
10 - 2 .
11 - 3 .
12 - 2 +
13 - 3 +
14 - 3 +
15 - 4 +
---
...
*/

//******************************************************************************//
class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};
        vector<int> ans(n + 1, 0);
        ans[1] = 1;
        int start = 2, halfRange = 1;
        for(; start <= n; ) {
            for(int i = start; i <= min(n, start + halfRange); i++)
                ans[i] = ans[i - halfRange];
            for(int i = start + halfRange; i <= min(n, start + 2 * halfRange); i++)
                ans[i] = ans[i - start] + 1;
            start <<= 1;
            halfRange <<= 1;
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 88.16% of C++ online submissions for Counting Bits.
Memory Usage: 7.9 MB, less than 75.07% of C++ online submissions for Counting Bits.
*/
