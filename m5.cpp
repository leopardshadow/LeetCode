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