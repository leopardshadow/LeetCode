
// 2022.10.10

/*
Greedy
對於前半部字串，從頭依序檢查，如果有非 a，就把它改為 a 後回傳
如果前半部字串都沒有 a，那就把尾巴改成 b
---
只要檢查前半部字串有沒有非 a 就好，因為他是 palindrome!
只找前半部還可以避開 xbx -> xax 的問題
*/

class Solution {
public:
    string breakPalindrome(string s) {
        if (s.length() == 1)
            return "";
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }
        s[s.length() - 1] = 'b';
        return s;
    }
};
/*
Runtime: 3 ms, faster than 45.61% of C++ online submissions for Break a Palindrome.
Memory Usage: 6.2 MB, less than 78.51% of C++ online submissions for Break a Palindrome.
*/
