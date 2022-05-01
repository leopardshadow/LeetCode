
// 2022.5.1

/*
TC 和 SC 都是 O(n) 的寫法很直接
---
SC 是 O(1) 的寫法可以倒著做，比較容易知道這個 char 會不會在最後結果裡~
*/

class Solution {
    string cal(string &s) {
        string res = "";
        for (const char &c : s) {
            if (c == '#') {
                if (res.length())
                    res.pop_back();
            }
            else
                res.push_back(c);
        }
        return res;
    }
public:
    bool backspaceCompare(string s, string t) {
        return cal(s) == cal(t);
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
Memory Usage: 6.2 MB, less than 68.92% of C++ online submissions for Backspace String Compare.
*/
