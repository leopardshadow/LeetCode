/*
s 
   0 1 2 3 4 5 6 7 ...
*/

class Solution {

public:
    string longestPalindrome(string s) {
        //
        int maxLen = 1;
        string ans = s.substr(0, 1);
        
        for(int i = 0; i < s.length(); i++) {
            //      v   
            //  y x a x y 
            //  |---|---|
            int step = 1;
            while(i - step >= 0 && i + step < s.length()) {
                if(s[i - step] == s[i + step]) {
                    // if it is new max
                    if(2 * step + 1 > maxLen) {
                        maxLen = 2 * step + 1;
                        ans = s.substr(i - step, 2 * step + 1);
                    }
                }
                else break;
                step++;
            }
            //    v
            //  x a a x
            step = 0;
            while(i - step >= 0 && i + step + 1 < s.length()) {
                if(s[i - step] == s[i + step + 1]) {
                    // if it is new max
                    if(2 * (step + 1) > maxLen) {
                        maxLen = 2 * (step + 1);
                        ans = s.substr(i - step, 2 * (step + 1));
                    }
                }
            else break;
            step++;
            }
        }
        return ans;
    }
};

/*
Runtime: 36 ms, faster than 70.87% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 24.7 MB, less than 44.03% of C++ online submissions for Longest Palindromic Substring.
*/



//***************************************************************************//
// Review: 2021.11.28 before G VO

/*
好久沒複習，一直 WA @@
主要重點是「兩種 palindrome」: aba 和 abba
從他們的中心點開始往左右擴張長出去

還有一開始在 WA 居然是因為 if 的 body 忘了用 {} 包起來
看來即使只有單行，多用 {} 還是比較好，不會忘了加
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
        string ans = s.substr(0, 1);
        for(int i = 0; i < s.length(); i++) {
            // a b a
            for(int len = 1; i - len >= 0 && i + len < s.length(); len++) {
                if(s[i + len] == s[i - len]) {
                    if(2 * len + 1 > maxLen) {
                        ans = s.substr(i - len, 2 * len + 1);
                        maxLen = 2 * len + 1;
                    }
                }
                else
                    break;
            }
            // a b b a
            for(int len = 0; i - len >= 0 && i + len + 1 < s.length(); len++) {
                if(s[i + len + 1] == s[i - len]) {
                    if(2 * len + 2 > maxLen) {
                        ans = s.substr(i - len, 2 * len + 2);
                        maxLen = 2 * len + 2;
                    }
                }
                else
                    break;
            }
        }
        return ans;
    }
};
