
// 2022.2.9

/*
要特別處理 k = 0 的情況
---
注意他題目要求的是 unique pair，一開始會想用 set 而不是 map
但是 k = 0 需要知道有 1 個還是 n 個
如果 k != 0，其實用 set 就好
---
因為要求 unique，所以我統一從小的來看：讓 n 去找 n + k
找的部分就用 map 惹
*/


// 2022.2.9

/*
要特別處理 k = 0 的情況
---
注意他題目要求的是 unique pair，一開始會想用 set 而不是 map
但是 k = 0 需要知道有 1 個還是 n 個
---
因為要求 unique，所以我統一從小的來看：讓 n 去對到 n + k
---
if(m[it.first + k] > 0)
vs.
if(m.find(it.first + k) != m.end())
哪裡不一樣？？？
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        for(const int &n : nums)
            m[n]++;
        if(k == 0) {
            for(const auto &it : m)
                if(it.second > 1)
                    ans += 1;
        }
        else {
            for(const auto &it : m)
                if(m.find(it.first + k) != m.end())
                    ans += 1;
        }
        return ans;
    }
};

/*
Runtime: 20 ms, faster than 73.03% of C++ online submissions for K-diff Pairs in an Array.
Memory Usage: 13.1 MB, less than 73.32% of C++ online submissions for K-diff Pairs in an Array.
*/
