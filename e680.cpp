
// 2022.4.2

/*
To-do: 好像有更優雅的解法
*/

class Solution {
    bool validPalindrome(string &s, int head, int tail, bool change) {
        while (head < tail) {
            if (s[head] == s[tail]) {
                head++;
                tail--;
            }
            else {
                if (change)
                    return false;
                return validPalindrome(s, head + 1, tail, true) ||
                       validPalindrome(s, head, tail - 1, true);
            }
        }
        return true;

    }
public:
    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.length() - 1, false);
    }
};

/*
Runtime: 60 ms, faster than 80.88% of C++ online submissions for Valid Palindrome II.
Memory Usage: 19.5 MB, less than 95.14% of C++ online submissions for Valid Palindrome II.
*/
