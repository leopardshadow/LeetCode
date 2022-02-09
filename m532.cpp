
// 2022.2.9

/*
要特別處理 k = 0 的情況
---
注意他題目要求的是 unique pair，一開始會想用 set 而不是 map
但是 k = 0 需要知道有 1 個還是 n 個
如果 k != 0，其實用 set 就好
---
因為要求 unique，所以我統一從小的來看：讓 n 去對到 n + k
---
(1) if(m[it.first + k] > 0)
vs.
(2) if(m.find(it.first + k) != m.end())
哪裡不一樣？？？
---
Ans:
(1) 會 insert，邊跑 loop 邊 insert 要小心，如果同樣的 code 改成 map 就會 TLE，他一直 insert 新的 (with default constructor)，新的又會繼續 insert 新的
雖然用 [] 取 map 的值很方便，但感覺還是 find 比較安全！！
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
