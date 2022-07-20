
// 2022.7.20

/*
幫 string s 的每一位 char 記錄他下一個 a-z 的位置
迴圈內位置一次更新一個
---
如果 word 跑到底，但 string s 紀錄的位置還沒到底 (-1)，就代表可以由他組成！
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> arr(n, vector<int>(26));
        vector<int> last(26, -1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++)
                arr[i][j] = last[j];
            last[s[i] - 'a'] = i;
        }
        
        int ans = 0;
        for (const string &w : words) {
            int idx = last[w[0] - 'a'];
            for (int i = 1; i < w.size(); i++) {
                if (idx >= 0)
                    idx = arr[idx][w[i] - 'a'];
                else
                    break;
            }
            ans += (idx >= 0 ? 1 : 0);
        }
            
        return ans;
    }
};
/*
Runtime: 1559 ms, faster than 5.03% of C++ online submissions for Number of Matching Subsequences.
Memory Usage: 387.5 MB, less than 5.20% of C++ online submissions for Number of Matching Subsequences.
*/
