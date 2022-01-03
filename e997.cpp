
// 2022.1.3

/*
發現 Leetcode 的 easy 題通常會有很多限制 (讓題目變得簡單)
---
例如這題它說所有 trust 的 pair 都會是 unique 的，所以對於 [?, a]
如果我想知道有幾個人相信 a，只要去數個數就好，不用在意 ? 有沒有重複、有沒有在範圍外
---
上面是其中一個條件，另一個條件是 the town judge trusts nobody
所以我把 [a, ?] 中的所有 a 設成一個很小很小的值，因為 a 不會是 the town judge
---
題目又說指會有一個人滿足上面兩個條件，所以只要遇到對的人就可以直接回傳，沒有的話就回傳 -1
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> people(n + 1, 0);
        for(const auto &t : trust) {
            people[t[1]]++;
            people[t[0]] = -100000;   
        }
            
        for(int i = 1; i <= n; i++)
            if(people[i] == n - 1)
                return i;
        return -1;
    }
};

/*
Runtime: 148 ms, faster than 89.17% of C++ online submissions for Find the Town Judge.
Memory Usage: 60.7 MB, less than 91.19% of C++ online submissions for Find the Town Judge.
*/
