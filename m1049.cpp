/*
Hint.
這題不要想成 s0 - s1 + s2 + s3 - s4 之類的，
而是要看成 (s0 + s2 + s3) - (s1 + s4)
這樣就變成 416. Partition Equal Subset Sum 了
---
一開始在想的時候有個小盲點：兩顆石頭都是一正一負消去的，但不代表對應到原始石頭的正負號數量會差不多
例如 5 1 1 1 1 1 是可以消成 0 的，但對應的正負是 + - - - - - (或全部反過來)
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int s : stones)
            sum += s;
        int targ = sum / 2;
        vector<int> dp(targ + 1, 0);
        for(int s : stones) {
            for(int w = targ; w >= s; w--) {
                dp[w] = max(dp[w], dp[w-s] + s);
            }
        }
        return (sum - dp[targ]) - dp[targ];
    }
};

/*
Runtime: 4 ms, faster than 82.89% of C++ online submissions for Last Stone Weight II.
Memory Usage: 8.3 MB, less than 61.47% of C++ online submissions for Last Stone Weight II.
*/
