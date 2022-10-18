
// 2022.10.18

/*
string
*/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            int cnt = 1;
            string t = "";
            s += ".";
            for (int j = 1; j < s.length(); j++) {
                if (s[j-1] == s[j])
                    cnt++;
                else {
                    t += to_string(cnt) + s[j-1];
                    cnt = 1;
                }
            }
            s = t;
        }
        return s;
    }
};
/*
Runtime: 8 ms, faster than 78.55% of C++ online submissions for Count and Say.
Memory Usage: 6.7 MB, less than 56.81% of C++ online submissions for Count and Say.
*/
