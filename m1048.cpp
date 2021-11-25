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
