
// 2022.3.27

/*
其實只要 top K 的話用 heap 比較有效率
*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;
        for (int r = 0; r < mat.size(); r++) {
            int rowSum = 0;
            for (int c = 0; c < mat[0].size(); c++) {
                rowSum += mat[r][c];
            }
            rows.push_back({rowSum, r});
        }
        sort(rows.begin(), rows.end());
        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(rows[i].second);
        return ans;
    }
};
/*
Runtime: 18 ms, faster than 46.89% of C++ online submissions for The K Weakest Rows in a Matrix.
Memory Usage: 10.5 MB, less than 75.81% of C++ online submissions for The K Weakest Rows in a Matrix.
*/
