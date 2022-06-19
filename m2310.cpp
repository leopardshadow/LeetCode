
// Weekly Contest 298
// 2022.6.19

/*
今天好考驗細心程度 @@
這題 (Q2) 和 Q3 各錯了兩次，總共加了 20 分鐘
---
這題問用最少個結尾是 k 的數字加起來，讓他結果是 num，問這個最小數字是多少
結尾是 k 的數字可以寫成 10x + k，所以看的是把 num 減掉 ans 個 k 後，可不可以被 10 整除
---
我的兩個錯誤是沒有考慮到 num == 0 和 k == 0 的情況 (各錯一次 = =)
---
num == 0 的話，不用取就符合，答案是 0
k == 0 的話，不管怎麼減 (num - n k) 都不會變小，所以看的是原本能不能被 10 整除
*/

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0)
            return 0;
        if (k == 0) {
            if (num % 10 == 0)
                return 1;
            else
                return -1;
        }
        int cnt = 1;
        for ( ; num - k * cnt >= 0; cnt++) {
            if ((num - k * cnt) % 10 == 0)
                return cnt;
        }
        return -1;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Numbers With Units Digit K.
Memory Usage: 6 MB, less than 83.33% of C++ online submissions for Sum of Numbers With Units Digit K.
*/
