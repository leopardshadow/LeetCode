
// Biweekly Contest 79

/*
滿有趣的題目，乍看之下是 graph，但其實是 sorting 的題目
計算每個城市有幾條路連接並排序，照大小分配 1 到 n
*/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> xs(n, 0);
        for (auto &r : roads) {
            xs[r[0]]++;
            xs[r[1]]++;
        }
        sort(xs.begin(), xs.end());
                
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long long)xs[i] * (long long)(i+1);
        }
        return ans;
    }
};
/*
Runtime: 438 ms, faster than 100.00% of C++ online submissions for Maximum Total Importance of Roads.
Memory Usage: 112.8 MB, less than 100.00% of C++ online submissions for Maximum Total Importance of Roads.
*/
