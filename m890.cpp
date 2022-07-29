
// 2022.7.29

/*
用兩個 map
一開始只用一個，w = "ccc", p = "abb" 也會被加到 ans 裡，這樣是錯ㄉ
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        
        vector<string> ans;
        for (string &s : words) {
            vector<int> m1(26, -1), m2(26, -1);
            bool isTr = true;
            for (int i = 0; i < s.size(); i++) {
                if (m1[p[i] - 'a'] == -1 && m2[s[i] - 'a'] == -1) {
                    m1[p[i] - 'a'] = s[i] - 'a';
                    m2[s[i] - 'a'] = p[i] - 'a';
                }
                else if (m1[p[i] - 'a'] != s[i] - 'a' ||
                         m2[s[i] - 'a'] != p[i] - 'a') {
                    isTr = false;
                    break;
                }
            }
            if (isTr)
                ans.push_back(s);
        }
        
        return ans;
    }
};
/*
Runtime: 3 ms, faster than 90.27% of C++ online submissions for Find and Replace Pattern.
Memory Usage: 8 MB, less than 92.07% of C++ online submissions for Find and Replace Pattern.
*/
