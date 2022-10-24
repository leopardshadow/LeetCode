
// 2022.10.24

/*
全部試過一遍
*/

class Solution {
    int cnt1(int x) {
        int cnt = 0;
        while (x) {
            cnt++;
            x = x & (x - 1);
        }
        return cnt;
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), ans = 0;
        vector<int> dp(1, 0);
        for (int i = 0; i < n; i++) {
            int x = 0;
            bool dup = false;
            for (const char &c : arr[i]) {
                if (x & (1 << (c - 'a'))) {
                    dup = true;
                    break;
                }
                else {
                    x |= 1 << (c - 'a');
                }
            }
            if (!dup) {
                for (int i = dp.size() - 1; i >= 0; --i) {
                    int c = dp[i];
                    if ((c & x))
                        continue;
                    dp.push_back(c | x);
                    ans = max(ans, cnt1(c) + cnt1(x));
                }
            }
        }
        return ans;
    }
};
/*
Runtime: 13 ms, faster than 83.73% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
Memory Usage: 8.9 MB, less than 79.31% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
*/
