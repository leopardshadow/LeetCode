
// 2022.8.15

/*
原來羅馬數字是這樣的！
*/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int i = 0, ans = 0;
        while (i + 1 < s.size()) {
            if (m[s[i]] < m[s[i+1]]) {
                ans -= m[s[i]];
                ans += m[s[i+1]];
                i += 2;
            }
            else {
                ans += m[s[i]];
                i += 1;
            }
        }
        if (i < s.size())
            ans += m[s[i]];
        
        return ans;
    }
};
/*
Runtime: 15 ms, faster than 62.96% of C++ online submissions for Roman to Integer.
Memory Usage: 8.2 MB, less than 21.24% of C++ online submissions for Roman to Integer.
*/
