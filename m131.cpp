
// 2022.1.5

/*
backtracking!
Related Topics 還寫到 DP，但我沒用到
*/

class Solution {
    vector<vector<string>> ans;
    vector<string> part;
    string s;
    
    void backtrack(int i) {
        if(i == s.size()) {
            ans.push_back(part);
        }
        
        for(int len = 1; len + i <= s.size(); len++) {
            
            bool isPalin = true;
            
            for(int j = 0; j < len / 2; j++) {
                if(s[i + j] != s[i + len - 1 - j]) {                    
                    isPalin = false;
                    break;
                }
            }
            
            if(!isPalin)
                continue;
            
            part.push_back(s.substr(i, len));
            backtrack(i + len);
            part.pop_back();
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        backtrack(0);
        return ans;
    }
};

/*
Runtime: 245 ms, faster than 17.05% of C++ online submissions for Palindrome Partitioning.
Memory Usage: 75.7 MB, less than 43.97% of C++ online submissions for Palindrome Partitioning.
*/
