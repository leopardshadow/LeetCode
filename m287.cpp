
// 2022.3.29

/*
今天這題題目的要求滿簡單的，但要求就比較麻煩了
1. 不改原本的陣列
2. constant extra space
3. linear time
這三個條件都要滿足的話其實不簡單，我想到的作法都沒有全部符合的
---
看了解答居然是用 cycle detection (龜🐢 兔🐰 賽跑) 的方式 ...
*/

// 不符合他的要求的作法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for (const int &n : nums) {
            if (s.count(n))
                return n;
            else
                s.insert(n);
        }
        return -1; // never return this
    }
};
/*
Runtime: 327 ms, faster than 10.17% of C++ online submissions for Find the Duplicate Number.
Memory Usage: 85.6 MB, less than 10.75% of C++ online submissions for Find the Duplicate Number.
*/
