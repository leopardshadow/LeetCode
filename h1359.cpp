
// 2022.3.6

/*
這週是 DP 週，印象中題目都和 DP 有關係
---
n = 2 時長這樣，四個 _ 表示放置 P 和 D，.表示空位
. _ . _ . _ . _ .
當我們要多放一組 P/D 進去時，有兩種選擇
1. 從中選擇兩個 . 的位置來放，前面是 P，後面是 D
2. 從中選擇一個 . 來放 P/D
所以 dp[n] = dp[n-1] * ( C^(2n-1)_2 + C^(2n-1)_1 )
---
一開始我是存整個 dp 陣列，但寫完後發現他只和前一個有關，不需要整個存起來
*/

class Solution {
public:
    int countOrders(int n) {
        vector<long long> dp(n + 1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int s = 2 * i - 1;  // number of spaces
            dp[i] = dp[i-1] * (s * (s-1) / 2 + s) % 1000000007;
        }
        return (int)dp.back();
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
Memory Usage: 6.3 MB, less than 27.99% of C++ online submissions for Count All Valid Pickup and Delivery Options.
*/



class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        for(int i = 2; i <= n; i++) {
            int s = 2 * i - 1;  // number of spaces
            ans = ans * (s * (s-1) / 2 + s) % 1000000007;
        }
        return (int)ans;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
Memory Usage: 5.9 MB, less than 82.70% of C++ online submissions for Count All Valid Pickup and Delivery Options.
*/
