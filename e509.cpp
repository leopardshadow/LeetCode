// DP Day 1

/*
0 1 2 3 5 8 13 
a b
*/
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, tmp;
        while(n) {
            tmp = b;
            b = a + b;
            a = tmp;
            n--;
        }
        return a;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
Memory Usage: 5.8 MB, less than 79.40% of C++ online submissions for Fibonacci Number.
*/


// 2022.7.6
// 要開始輪 DP 了嗎 ><
