class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int, bool> m;
        for(const auto n : nums) {
            // there is duplicate
            if(m.find(n) != m.end())
                return true;
            // no duplicate number
            else
                m[n] = true;
        }
        return false;
    }
};

/*
Runtime: 48 ms, faster than 33.31% of C++ online submissions for Contains Duplicate.
Memory Usage: 21 MB, less than 30.71% of C++ online submissions for Contains Duplicate.
*/