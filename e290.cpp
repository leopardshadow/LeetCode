
// 2022.1.17

/*
一開始我把 string.find 的兩個參數 (找的目標和位置弄反)
因為 char 和 int 可以互相轉型，所以 compiler 也沒報錯
這其實不應該記反的，因為參數一定要目標，但不一定要起始位置
所以一定是把找尋目標放前面，起始位置放後面才合理
---
這題雖然是列在 easy，但有點麻煩 ... 有好多小細節要注意
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        int start = 0, end;
        string word;
        string m[26] = {""};
        unordered_map<string, char> um;
        
        s = s + " ";
        
        for(const char &pat : pattern) {
            end = s.find(' ', start);
            word = s.substr(start, end - start);
            if(m[pat - 'a'] == "" && um.find(word) == um.end()) {
                m[pat - 'a'] = word;
                um[word] = pat;  
            }
            else if(m[pat - 'a'] != word)
                return false;
            else if(um[word] != pat)
                return false;
            start = end + 1;
        }
        
        return end == s.length() - 1;
    }
};

/*
Runtime: 2 ms, faster than 23.56% of C++ online submissions for Word Pattern.
Memory Usage: 6.4 MB, less than 50.50% of C++ online submissions for Word Pattern.
*/

// 2023.1.1
// Happy New Year!

