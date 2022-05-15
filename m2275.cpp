
// Weekly Contest 293

/*
滿喜歡 bit operation 類的題目 XD
想法是，不為 0 的數代表以二進位表示時必定有至少一位是 1
把每個都跑過一次算有幾個數字那位也是 1 就可以收工啦
---
吃一個 WA，因為一開始 i 寫成從 1 開始，應該要從 0 開始，不然會漏掉 00..01
*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0, mask = 1 << i;
            for (const int &n : candidates) {
                if (n & mask)
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
/*
Runtime: 173 ms, faster than 66.67% of C++ online submissions for Largest Combination With Bitwise AND Greater Than Zero.
Memory Usage: 57.5 MB, less than 33.33% of C++ online submissions for Largest Combination With Bitwise AND Greater Than Zero.
*/
