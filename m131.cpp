
// 2022.1.5

/*
backtracking!
---
~~Related Topics 還寫到 DP，但我沒用到~~
DP 的部分加了紀錄誰是 palindrone，遇到先前遇過的就不用再判斷一次
---
一開始在判斷是不是迴圈的 j-loop break/continue 沒弄好，一次只跳一層RRRR 
*/

class Solution {
    vector<vector<string>> ans;
    vector<string> part;
    string s;
    uint8_t dp[17][17];
    
    void backtrack(int i) {
        if(i == s.size()) {
            ans.push_back(part);
        }
        
        for(int len = 1; len + i <= s.size(); len++) {
            
            bool isPalin = true;
            
            if(dp[i][i + len - 1] == 0) {
                for(int j = 0; j < len / 2; j++) {
                    if(s[i + j] != s[i + len - 1 - j]) {                    
                        isPalin = false;
                        dp[i][i + len - 1] == 1;
                        break;
                    }
                }
                dp[i][i + len - 1] == 2;
            }
            else
                isPalin = (dp[i][i + len - 1] == 2);
            
            if(!isPalin)
                continue;
            
            part.push_back(s.substr(i, len));
            backtrack(i + len);
            part.pop_back();
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        for(int i = 0; i < 17; i++)
            for(int j = 0; j < 17; j++)
                dp[i][j] = 0;
        this->s = s;
        backtrack(0);
        return ans;
    }
};

/*
Runtime: 166 ms, faster than 38.56% of C++ online submissions for Palindrome Partitioning.
Memory Usage: 75.6 MB, less than 47.79% of C++ online submissions for Palindrome Partitioning.
*/
