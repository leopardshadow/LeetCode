
// 2022.1.2
// 昨天的 Hard 好難，之後再來慢慢研究 QQ
// 已經 2022 了啦，一開始還打成 2021

/*
這題要找到所有 pair 總和是 60 的倍數的個數
---
所以只要儲存 mod 60 後的值就好，接著去配對

 0 -- 60 **
 1 -- 59
 2 -- 58
 ..
29 -- 31
30 -- 30 **

** : C^n_2 = n * (n - 1) / 2
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mod[60] = {0};
        for(const int &t : time)
            mod[t % 60]++;
        
        int ans = 0;
        //  1 .. 59
        //  2 .. 58
        // 29 .. 31
        for(int i = 1; i <= 29; i++) {
            ans += mod[i] * mod[60 - i];
        }
        // 0 (60)
        if(mod[0] >= 2)
            ans += mod[0] * (mod[0] - 1) / 2;
        
        // 30 -- 30
        if(mod[30] >= 2)
            ans += mod[30] * (mod[30] - 1) / 2;
        
        return ans;
    }
};

/*
Runtime: 35 ms, faster than 39.37% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
Memory Usage: 23.1 MB, less than 90.11% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
*/
