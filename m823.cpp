
// 2022.8.9

/*
明顯的 DP~
*/

typedef long L;
L M = 1000000007;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        // maps value to index
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[arr[i]] = i;
        
        vector<L> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int q = arr[i] / arr[j];
                    if (m.find(q) != m.end()) {
                        dp[i] += (dp[j] * dp[m[q]]) % M;
                    }
                }
            }
        }
        
        L ans = 0;
        for (const L &d: dp) {
            ans = (ans + d) % M;
        }
        
        return ans;
    }
};
/*
Runtime: 61 ms, faster than 91.69% of C++ online submissions for Binary Trees With Factors.
Memory Usage: 9.2 MB, less than 81.85% of C++ online submissions for Binary Trees With Factors.
*/
