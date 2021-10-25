/*
s = w + ws, where w is in wordDict (if no such w exists, return false)
f(s) will return true if  f(ws) is true
*/

class Solution {
private:
    // check if l's prefix is s
    // l & s are strings and l is longer than s
    bool prefixEqual(string l, string s) {
                
        // e.g. s = "hi", wordDict = ["hello", "hola"]
        // should retuen false
        if(l.size() < s.size()) {
            return false;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(l[i] != s[i])
                return false;
        }
        return true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = false;
        for(int i = 0; i < wordDict.size(); i++) {
            if(s == wordDict[i])
                return true;
            if(prefixEqual(s, wordDict[i])) {
                ans = wordBreak(s.substr(wordDict[i].length()), wordDict);
                if(ans) return true;
            }
        }
        return false;
    }
};

// TLE for now