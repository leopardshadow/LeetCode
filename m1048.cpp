/*
Hint 1 from Leetcode
Instead of adding a character, try deleting a character to form a chain in reverse.
這個提示對我滿關鍵的，用新增的話不知道到底要加在哪裡，用減的話，找到第一個不一樣的就把它當成新加的，如果後面還發現有不一樣的，那他們倆就不能形成 chain

// 暫存
// ERROR with both ...
*/

class Record {
public:
    string str;
    int cnt;
    Record(string str) {
        this->str = str;
        cnt = 1;
    }
};

class Solution1 {
    bool isPred(const string &shorter, const string &longer) {
        int diff = 0;
        for(int i = 0; i < shorter.length(); i++) {
            if(shorter[i] != longer[i+diff]) {
                if(diff == 0)
                    diff = 1;
                else
                    return false;
            }
        }
        if(diff == 1)  // 重要，一開始忘了加
            return shorter.back() == longer.back();
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        vector<Record> sortByLen[17];
        for(int i = 0; i < words.size(); i++)
            sortByLen[words[i].length()].push_back(Record(words[i]));
        int ans = 1;
        for(int len = 2; len <= 16; len++) {
            for(Record &r2 : sortByLen[len]) {
                for(const Record &r1 : sortByLen[len-1]) {
                    if(isPred(r1.str, r2.str)) {
                        r2.cnt = max(r2.cnt, r1.cnt + 1);
                        ans = max(ans, r2.cnt);
                    }
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m[17];
        for(string w : words)
            m[w.length()][w] = 1;
        
        int ans = 1;
        for(int l = 2; l <= 16; l++) {
            for(auto it = m[l].begin(); it != m[l].end(); it++) {
                string s = it->first;
                for(int i = 0; i < s.size(); i++) {
                    if(m[l-1].find(s.substr(0, i) + s.substr(i+1)) != m[l-1].end())
                        it->second = max(it->second, m[l-1][s.substr(0, i) + s.substr(i+1)]);
                    ans = max(ans, it->second);
                }
            }
        }
        return ans;
    }
};

//******************************************************************************//

// 2022.6.15

/*
原來去年 2021.11.26 G VO 之前就嘗試寫過，但一直 WA (上面都 WA 嗚嗚嗚)
---
A 是 B 的 predecessor <=> A 插一個字就可以變成 B (所以他們長度差 1)
---
我先把所有 words 依據長度分類，接著把長度為 n+1 的字串 (a) 一一輪流和長度 n 的所有字串 (b) 比較，如果他們符合 predecessor 的關係，dp[a] = max(dp[a], dp[b] + 1), ans = max(ans, dp[a])
---
看討論區有更快的作法 ><
*/

class Solution {
    // s1 - shorter, s2 - longer
    bool isPred(const string &s1, const string &s2) {
        int i = 0, j = 0;
        while (j < s2.length()) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            }
            else
                j++;
        }
        if(i == s1.length() && j == s2.length()) 
            return true;
        else 
            return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m[17];
        for (string w : words)
            m[w.length()][w] = 1;
        
        int ans = 1;
        for (int l = 2; l <= 16; l++) {
            for (auto it = m[l].begin(); it != m[l].end(); it++) {
                string s = it->first;
                for (auto it2 = m[l-1].begin(); it2 != m[l-1].end(); it2++) {
                    if (isPred(it2->first, s))
                        it->second = max(it->second, it2->second + 1);
                }
                ans = max(ans, it->second);
            }
        }
        return ans;
    }
};
/*
Runtime: 55 ms, faster than 95.70% of C++ online submissions for Longest String Chain.
Memory Usage: 18.1 MB, less than 45.77% of C++ online submissions for Longest String Chain.
*/
