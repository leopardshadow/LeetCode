class Solution {
public:
    
    vector<vector<int>> ans;
    
    void subset(vector<int> &ss, unordered_map<int, int>::iterator cur, unordered_map<int, int> &m) {
        if(cur == m.end()) {
            ans.push_back(ss);
            return;
        }
        subset(ss, next(cur), m);
        for(int i = 1; i <= cur->second; i++) {
            ss.push_back(cur->first);
            subset(ss, next(cur), m);
        }
            for(int i = 1; i <= cur->second; i++) {
            ss.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int n : nums)
            m[n]++;
        vector<int> ss;
        subset(ss, m.begin(), m);
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets II.
Memory Usage: 11.8 MB, less than 18.99% of C++ online submissions for Subsets II.
*/