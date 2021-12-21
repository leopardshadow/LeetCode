
// 2021.12.21 冬至 下雨 好冷 XD

/*
[先考慮正數]
這題要算 power of 2，2 的次方的數字寫成二進位表示的話只會有一個 1，其他都是 0，例如

1 = 2^0 = 0..000001
2 = 2^1 = 0..000010
4 = 2^2 = 0..000100
8 = 2^3 = 0..001000

所以確定有 1 之後(非全 0，0)，拔掉一個 1 後，這個數字會變成 0
而拔掉 1 很常用：n & (n - 1)
---
負數的話不能把它轉正處理，因為題目的意思是 2^x，負數根本造不出來，可以直接回傳 false
如果負數也算的話就要特別處理 -2^31
-1 = 1..111111
-2 = 1..111110
-3 = 1..111100
---
(一開始以為是這樣，但負的不合題目要求，都可以回傳 false)
要特別注意的是 n 的範圍是 -2^31 <= n <= 2^31 - 1
有一個 n 不能 -1，那就是  -2^31
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        n = n & (n - 1);
        return n == 0;
    }
};

// 我沒有多用到任何一個變數欸，到底 memory 是怎麼計算的

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Two.
Memory Usage: 5.9 MB, less than 22.94% of C++ online submissions for Power of Two.
*/


