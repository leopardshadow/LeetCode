
// Weekly Contest 273
// Dec 26
// NP P4 崩潰 QQ

/*
這其實就按照題目說的寫出來而已，沒用到什麼特殊的演算法
(一開始先寫下一題：2121 還以為這個會有特殊解法/ ...)
*/

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        vector<int> ans(s.length(), 0);
            
        for(int i = 0; i < s.length(); i++) {
            
            int r = startPos[0], c = startPos[1];
            int l;
            bool stop = false;
            for(l = 0; i + l < s.length(); l++) {
                switch(s[i + l]) {
                        
                    case 'R':
                        c += 1;
                        if(c >= n) stop = true;
                        break;
                        
                    case 'L':
                        c -= 1;
                        if(c < 0) stop = true;
                        break;
            
                    case 'U':
                        r -= 1;
                        if(r < 0) stop = true;
                        break;
                        
                    case 'D':
                        r += 1;
                        if(r >= n) stop = true;
                        
                        break;
                }
                if(stop)
                    break;
            }
            ans[i] = l;
        }
        return ans;
    }
};

/*
Runtime: 24 ms, faster than 64.29% of C++ online submissions for Execution of All Suffix Instructions Staying in a Grid.
Memory Usage: 10.2 MB, less than 28.57% of C++ online submissions for Execution of All Suffix Instructions Staying in a Grid.
*/
