// 2022.1.22

/*
這題 hard 的輸入、輸出也太精簡XD
輸入只有一個 int，輸出更是只有 true/false
---
好怕這種題目，Game Theory + DP
---
寫出 1, 2, 3, 4, 5 ... 幾個例子後就可以看出是 DP
*/

class Solution {
    vector<int> dp;
    bool solve(int n) {
        if(dp[n] != 0)
            return (dp[n] == 1);
        
        for(int i = 1; n - i*i >= 0; i++) {
            if(!solve(n - i*i)) {   // 這個 negation 是關鍵，因為是輪流去拿，而且大家都會 optimally 拿
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = -1;
        return false;
    }
public:
    bool winnerSquareGame(int n) {
        
        for(int i = 0; i <= n; i++)
            dp.push_back(0);
        
        //  1 -> Alice wins
        // -1 -> Bob wins
        dp[0] = -1;
        dp[1] = 1;
          
        return solve(n);
    }
};

/*
Runtime: 137 ms, faster than 36.58% of C++ online submissions for Stone Game IV.
Memory Usage: 14.3 MB, less than 14.77% of C++ online submissions for Stone Game IV.
*/
