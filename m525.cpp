
// 2022.2.4

/*
發現 LeetCode 喜歡把性質類似的題目擺在附近天 (?)
---
第一想法是暴力解，把所有可能都列出來，應該會 TLE，略
---
看了討論區
先把 0 -> -1, 1 -> 1
這樣一來，如果 [0, i] 和 [0, j] 的總和分別都是 m，那 [i+1, j] 的和是 m - m = 0
代表這個區間內有一樣多的 0 和 1。
*/

/*
這個會 WA 的作法 522 / 564 test cases passed.
到底 ... QQ
*/
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         set<pair<int, int>> s;
//         vector<pair<int, int>> v;
//         int cnt[2] = { 0 };
//         for(const int &n : nums) {
//             cnt[n]++;
//             s.insert({cnt[0], cnt[1]});
//             v.push_back({cnt[0], cnt[1]});
//         }
//         int ans = 0;
//         for(int i = nums.size() - 1; i >= 0; i--) {
//             int c0 = v[i].first, c1 = v[i].second;
//             if(c0 == c1)
//                 ans = max(ans, 2 * c0);
//             else if(c0 > c1) {
//                 if(s.count({c0 - c1, 0}))
//                     ans = max(ans, 2 * c1);
//             }
//             else {  // c0 < c1
//                 if(s.count({0, c1 - c0}))
//                     ans = max(ans, 2 * c0);
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;  // !!!
        int ans = 0, s = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                s -= 1;
            else
                s += 1;
            if(m.find(s) == m.end())
                m[s] = i;
            else
                ans = max(ans, i - m[s]);
        }
        return ans;
    }
};

/*
Runtime: 275 ms, faster than 11.70% of C++ online submissions for Contiguous Array.
Memory Usage: 83.8 MB, less than 86.74% of C++ online submissions for Contiguous Array.
*/
