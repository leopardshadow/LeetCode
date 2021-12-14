// Hint: DP

/*
這題原題可以從 wordDict 取零或多個 word 來使用，因此可以很簡單的用 DP 來解
但如果改成最多只能取用一次就比較麻煩了 (0-1 背包問題 vs. 無限背包問題 ?)
我嘗試用 DFS 解原題，但是會 TLE
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
                
        // 紀錄 substring(0, i)  (從 0 開始數 i 個 character) 可不可以組成
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        
        for(int i = 0; i <= s.length(); i++) {
            
            if(!dp[i]) continue;
            
            for(string word : wordDict) {
                if(s.substr(i, word.length()) == word)
                    dp[i + word.length()] = true;
            }
        
        }
        return dp[s.length()];
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Break.
Memory Usage: 7.3 MB, less than 99.89% of C++ online submissions for Word Break.
*/



/*
s = w + ws, where w is in wordDict (if no such w exists, return false)
f(s) will return true if  f(ws) is true
*/

// class Solution {
// private:
//     // check if l's prefix is s
//     // l & s are strings and l is longer than s
//     bool prefixEqual(string l, string s) {
                
//         // e.g. s = "hi", wordDict = ["hello", "hola"]
//         // should retuen false
//         if(l.size() < s.size()) {
//             return false;
//         }
        
//         for(int i = 0; i < s.size(); i++) {
//             if(l[i] != s[i])
//                 return false;
//         }
//         return true;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         bool ans = false;
//         for(int i = 0; i < wordDict.size(); i++) {
//             if(s == wordDict[i])
//                 return true;
//             if(prefixEqual(s, wordDict[i])) {
//                 ans = wordBreak(s.substr(wordDict[i].length()), wordDict);
//                 if(ans) return true;
//             }
//         }
//         return false;
//     }
// };

// TLE for now



/*
0 1 2 3 4 5 6 7
l e e t c o d e
T.      T        T

*/

//***************************************************************************//
// DP D9
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> table(s.length() + 1, false);
        table[0] = true;
        for(int i = 0; i < s.length(); i++) {
            if(table[i]) {
                for(string w : wordDict) {
                    if(i + w.length() < table.size() && s.substr(i, w.length()) == w)
                        table[i + w.length()] = true;
                }
            }
        }
        return table.back();
    }
};

/*
Runtime: 9 ms, faster than 61.68% of C++ online submissions for Word Break.
Memory Usage: 7.6 MB, less than 96.06% of C++ online submissions for Word Break.
*/

// 嘗試用 DFS

class Solution {
    bool solve(const string &s, int start, vector<string>& wordDict) {
        
        if(s.substr(start) == "")
            return true;
        
        for(string w : wordDict) {
            if(s.substr(start, w.length()) == w)
                if(solve(s, start+w.length(), wordDict))
                    return true;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, 0, wordDict);        
    }
};
