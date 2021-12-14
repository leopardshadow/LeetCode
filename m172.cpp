/*
這題好像高中有出現過，要造出 10 一定要 2 和 5，其中 2 又比 5 多
所以這題其實就只是找 1...n 中出現了幾個 5
---
TC: log_5^n
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int log5 = 5;
        while(log5 <= n) {
            ans += n / log5;
            log5 *= 5;
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Factorial Trailing Zeroes.
Memory Usage: 5.9 MB, less than 28.03% of C++ online submissions for Factorial Trailing Zeroes.
*/
