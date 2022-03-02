
// 2022.3.2

/*
他 tag 標 dp，但我用的是 2-pointer 的作法
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()) {
            if(s[i] == t[j])
                i++;
            j++;
        }
        return i == s.length();
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
Memory Usage: 6.3 MB, less than 90.23% of C++ online submissions for Is Subsequence.
*/
