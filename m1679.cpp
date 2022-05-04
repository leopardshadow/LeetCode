
// 2022.5.4

/*
有點像 2-sum
---
map 的 range-based loop
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int sum) {
        map<int, int> m;
        for (const int &n : nums)
            m[n]++;
        
        int ans = 0;

        if (2 * (sum / 2) == sum) {  // if sum can be equally divided by 2
            ans += m[sum / 2] / 2;
            m[sum / 2] = 0;  // avoid count twice
        }
        
        for (auto& [k,v] : m) {
            if (k > sum / 2)
                break;
            if (m.count(sum - k)) {
                ans += min(v, m[sum - k]);
            }
        }
            
        return ans;
    }
};
/*
Runtime: 185 ms, faster than 56.80% of C++ online submissions for Max Number of K-Sum Pairs.
Memory Usage: 68.1 MB, less than 35.08% of C++ online submissions for Max Number of K-Sum Pairs.
*/
