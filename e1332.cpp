
// 2022.6.8

/*
一開始沒仔細看題目說明，以為這個 palindromic subsequence 必須要連續，但其實他沒有要求
知道這點後，答案其實最多只會是 2 (先刪掉全部的 a，再刪掉全部的 b)
答案是 1 的情況則是原字串原本就是 palindrome，所以刪一次就好
這裡 input string size 至少是 1，所以答案不會是 0，只會是 {0, 1}
---
有點腦筋急轉彎的題目 XD
就只是換個方式考 isPalindrome 而已
---
如果 subsequence 要連續感覺就不是 easy 等級的題目了
*/

class Solution {
public:
    int removePalindromeSub(string s) {
        for (int i = 0; i < s.length() / 2; i++)
            if (s[i] != s[s.length() - 1 - i])
                return 2;
        return 1;
    }
};
/*
Runtime: 4 ms, faster than 30.61% of C++ online submissions for Remove Palindromic Subsequences.
Memory Usage: 6.2 MB, less than 78.83% of C++ online submissions for Remove Palindromic Subsequences.
*/
