
// 2022.10.23

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        for (const int &n : nums)
            m[n]++;
        vector<int> ans(2);
        for (int i = 1; i <= nums.size(); i++) {
            if (m.find(i) == m.end())
                ans[1] = i;
            else if (m[i] == 2)
                ans[0] = i;
        }
        return ans;
    }
};
/*
Runtime: 155 ms, faster than 18.97% of C++ online submissions for Set Mismatch.
Memory Usage: 30.8 MB, less than 30.01% of C++ online submissions for Set Mismatch.
*/
