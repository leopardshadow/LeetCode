
// 2022.5.24

/*
哇，第一次秒殺 Hard 耶！！
只是我的作法不是用題目 Related Topcis 的 DP，而是用 sliding window
Time Complexity 是 O(n^2)，但這題 input 不大，所以沒有 TLE
DP (or maybe 改良過後的 sliding window) 應該可以做到 O(n)
但是 sliding window 的好處是 space complexity 是 O(1)，不需要額外建表
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        for (int end = 0; end < s.length(); end++) {
            int cnt = 0;
            for (int i = end; i >= 0; i--) {
                cnt += (s[i] == ')' ? +1 : -1);
                if (cnt < 0)
                    break;
                if (cnt == 0)
                    ans = max(ans, end - i + 1);
            }
        }
        return ans;
    }
};
/*
Runtime: 10 ms, faster than 23.62% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 6.8 MB, less than 96.04% of C++ online submissions for Longest Valid Parentheses.
*/
