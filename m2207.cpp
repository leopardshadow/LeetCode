
// Biweekly Contest 74 (2022.3.19)

/*
pattern 重複的話要另外處理 (WA 原因)
他這個 pattern 長度只有 2，所以比較簡單
包含 / 不包含的情況要注意
*/

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.length();
        vector<int> c0(n, 0), c1(n, 0);
        vector<bool> cal(n, false);
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < text.length(); i++) {
            if(text[i] == pattern[0]) {
                cnt0++;
                cal[i] = true;                
            }
            c0[i] = cnt0;
        }
        if(pattern[0] == pattern[1])
            cnt1 = -1;
        for(int i = text.length() - 1; i >= 0; i--) {
            if(text[i] == pattern[1])
                cnt1++;
            c1[i] = cnt1;
        }

        long long ans = 0, extra = 0;
        for(int i = 0; i < n; i++) {
            if(cal[i])
                ans += (long long)(c1[i]);
            extra = max(extra, (long long)c0[i]);
            extra = max(extra, (long long)c1[i]);
        }
        cout << ans << " " << extra << endl;
        return ans + extra;
    }
};
/*
Runtime: 117 ms, faster than 40.00% of C++ online submissions for Maximize Number of Subsequences in a String.
Memory Usage: 36.7 MB, less than 40.00% of C++ online submissions for Maximize Number of Subsequences in a String.
*/
