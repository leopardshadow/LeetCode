// Google

/*
分類的話應該算在 sliding window 類型的題目
我們要統計字串中，'a' 到 'z' 出現的次數和相異字元的數量
因為要回傳所有 good splits 的數量，所以沒什麼好說的，一定要所有切法都判斷一遍。
但這個判斷可以不用每次都重頭走，因為一個增長，一個就會縮短，呈現此消彼長的關係。
注意這裡的判斷條件，由於我是分成 0 ~ i 和 i+1 ~ end，
而一邊沒有東西，一邊全拿必定不會是 good split，所以在 for 迴圈判斷條件只要做到 n - 1
(多寫也是可以啦，但有點多餘就是了)
*/

class Solution {
    void addChar(map<char, int> &m, int &cnt, char c) {
        if(m[c] == 0)
            cnt++;
        m[c]++;
    }
    void delChar(map<char, int> &m, int &cnt, char c) {
        if(m[c] == 1)
            cnt--;
        m[c]--;
    }

public:
    int numSplits(string s) {
        int ans = 0;
        if(s.length() == 1)
            return 0;
        map<char, int> m1, m2;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < s.length(); i++)
            addChar(m2, cnt2, s[i]);
        // 0 ~ i / i+1 ~ end
        for(int i = 0; i < s.length() - 1; i++) {
            delChar(m2, cnt2, s[i]);
            addChar(m1, cnt1, s[i]);
            if(cnt1 == cnt2)
                ans++;
        }
        return ans;
    }
};

/*
Runtime: 60 ms, faster than 17.17% of C++ online submissions for Number of Good Ways to Split a String.
Memory Usage: 8.6 MB, less than 59.52% of C++ online submissions for Number of Good Ways to Split a String.
*/


//***************************************************************************//

// 不過其實根本不用用到 map，用 int [26] 就好，還快很多

class Solution {
    void addChar(int *m, int &cnt, char c) {
        if(m[c - 'a'] == 0)
            cnt++;
        m[c - 'a']++;
    }
    void delChar(int *m, int &cnt, char c) {
        if(m[c - 'a'] == 1)
            cnt--;
        m[c - 'a']--;
    }

public:
    int numSplits(string s) {
        int ans = 0;
        if(s.length() == 1)
            return 0;
        int m1[26] = {0}, m2[26] = {0};
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < s.length(); i++)
            addChar(m2, cnt2, s[i]);
        // 0 ~ i / i+1 ~ end
        for(int i = 0; i < s.length() - 1; i++) {
            delChar(m2, cnt2, s[i]);
            addChar(m1, cnt1, s[i]);
            if(cnt1 == cnt2)
                ans++;
        }
        return ans;
    }
};

/*
Runtime: 23 ms, faster than 78.56% of C++ online submissions for Number of Good Ways to Split a String.
Memory Usage: 8.4 MB, less than 95.98% of C++ online submissions for Number of Good Ways to Split a String.
*/
