class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        for(int layer = 1; layer < numRows; layer++) {
            ans[layer].push_back(1);
            for(int j = 1; j < ans[layer-1].size(); j++) {
                ans[layer].push_back(ans[layer-1][j-1] + ans[layer-1][j]);
            }
            ans[layer].push_back(1);
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
Memory Usage: 6.6 MB, less than 33.35% of C++ online submissions for Pascal's Triangle.
*/


// 2022.7.19
