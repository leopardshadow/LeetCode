class Solution {
    vector<vector<int>> ans;
    vector<int> c;
public:
    void comb(int start, int n, int k) {
        if (k == 0)
            ans.push_back(c);
        for(int i = start; i <= n; i++) {
            c.push_back(i);
            comb(i + 1, n, k - 1);
            c.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        comb(1, n, k);
        return ans;
    }
};

/*
Runtime: 34 ms, faster than 40.41% of C++ online submissions for Combinations.
Memory Usage: 10.1 MB, less than 40.97% of C++ online submissions for Combinations.
*/
