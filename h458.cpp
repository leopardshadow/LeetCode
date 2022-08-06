
// 2022.8.6

/*
這題的重點 (我覺得題目不清楚..) 是一隻豬一次可以喝不只一桶，一桶也不是只能分給一隻豬
---
Example 2:
buckets = 4, T = 1
         (pig)
bucket 0: _ _
bucket 1: A _
bucket 2: _ B
bucket 3: A B
(判斷有毒的情況)
       B 死了  B 活著
A 死了   3       1
A 活著   2       0
---
反過來想，如果給豬的數量 x 和試的次數 T，最後可以試岀幾個桶子
**每隻豬可能在在第 1, 2, 3, ... , T 次試驗的時候死掉，或沒死掉，總共有 (T+1) 種可能** <= key
每隻豬都有 (T+1) 種可能，因此全部是 (T+1) ^ x
(T+1) ^ x 要 >= N，其中要找最少的 x
接下來就是數學題了
---
可能是因為虐待動物，讚 = 1005，倒讚 = 2099 (?
*/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest / minutesToDie;
        return (int)ceil(log(buckets) / log(t+1));
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Poor Pigs.
Memory Usage: 6.1 MB, less than 22.55% of C++ online submissions for Poor Pigs.
*/
