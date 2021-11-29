class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for(int l = 0; l < rowIndex; l++) {
            for(int j = 1; j < ans.size(); j++)
                ans[j-1] += ans[j];
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
Memory Usage: 6.3 MB, less than 79.48% of C++ online submissions for Pascal's Triangle II.
*/
