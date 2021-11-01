// Hint: DP

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