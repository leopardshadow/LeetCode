
// 2022.1.31

/*
這題 easy 是真的 easy，應該是考語法ㄅ XD
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(const auto &account : accounts) {
            int sum = 0;
            for(const auto &n : account)
                sum += n;
            ans = max(ans, sum);
        }
        return ans;
    }
};

/*
Runtime: 7 ms, faster than 41.49% of C++ online submissions for Richest Customer Wealth.
Memory Usage: 7.8 MB, less than 49.93% of C++ online submissions for Richest Customer Wealth.
*/
