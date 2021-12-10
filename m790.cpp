// 2021.12.10

/*
Hint. DP
---
這是我原本的想法，多出來的一個有以下幾種放法

1. 放一個直的 2x1 => dp[i-1]
2. 放兩個橫的 1x2 => dp[i-2]
3. 放轉角型 (size 3)，他旁邊必定也是轉角型的，有 「」或轉 180 度的放法 => 2 * dp[i-3]

如果綜合以上，dp[i] = dp[i-1] + dp[i-2] + 2 * dp[i-3]
---

但是這樣得出的答案會比較小，主要差在 3 那項，漏了像這樣的
⬛ ⬜ ⬜ ⬛ ⬛ 
⬛ ⬛ ⬜ ⬜ ⬛

⬛ ⬛ ⬜ ⬜    ;   ⬛ ⬛ ⬜ ⬜ ⬛ ⬛ 
⬛  x x ⬜    ;   ⬛ ⬜ ⬜ ⬜ ⬜ ⬛

最後放轉角型的，他旁邊不一定要馬上就把它閉合
a. 馬上閉合的話，就是 2 * dp[i-3]
b. 不馬上閉合的話，是 2 * (dp[i-4] + dp[i-5] + ... + dp[1])

所以式子應該是 dp[i] = dp[i-1] + dp[i-2] + 2 * (dp[i-3] + dp[i-4] + ... + dp[1])
接下來是我覺得很酷的地方，高中數學常常做這樣的事，他拿 dp[i] - dp[i-1]
     dp[i]  = dp[i-1] + dp[i-2] + 2 * (dp[i-3] + dp[i-4] + ... + dp[1])
 -) dp[i-1] = dp[i-2] + dp[i-3] + 2 * (          dp[i-4] + ... + dp[1])
─────────────────────────────────────────────────────────────────────────
     dp[i]  = 2 * dp[i-1] + dp[i-3]

這就是最終 dp 的式子!!

(原來還有這樣相減的技巧啊..)

---
在討論區看到用兩條來分別記錄 Domino 和 Tromino，感覺比較好懂
*/

class Solution {
public:
    int numTilings(int n) {

        vector<unsigned int> dp(max(4, n + 1), 0);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        if(n <= 3)
            return dp[n];

        for(int i = 4; i <= n; i++) {
            dp[i] = (dp[i-3] + 2 *dp[i-1]) % 1000000007;
        }
        return dp[n];
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Domino and Tromino Tiling.
Memory Usage: 6.4 MB, less than 54.44% of C++ online submissions for Domino and Tromino Tiling.
*/
