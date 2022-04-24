
// Weekly Contest 290

/*
因為每個陣列裡的數字都是不同的所以滿直接的
*/

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> m;
        for (auto &ns : nums) {
            for (int &n : ns)
                m[n]++;
        }
        vector<int> ans;
        for (auto it : m) {
            if (it.second == nums.size())
                ans.push_back(it.first);
        }
        return ans;
    }
};
/*
Runtime: 15 ms, faster than 66.67% of C++ online submissions for Intersection of Multiple Arrays.
Memory Usage: 12.5 MB, less than 16.67% of C++ online submissions for Intersection of Multiple Arrays.
*/
