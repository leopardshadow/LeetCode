
// Biweekly Contest 76

/*
一開始就寫暴力解，結果 TLE
還以為要什麼特別的技巧，e.g. ax + by <= n 的整數點，結果想不出來怎麼做
回頭去看一開始交的 code，抱著嘗試的心態把轉型的部分拉出來到迴圈外，沒想到過了 OAO
---
因為他差點只有兩題 QQ
---
以下是 TLE 的 code ...
---
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int c1 = max(cost1, cost2), c2 = min(cost1, cost2);
        long long ans = 0;
        for (int c = total; c >= 0; c -= c1) {
            ans += (long long)(c / c2) + 1;
            cout << ans << endl;
        }
        
        return ans;
    }
};
*/

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long c1 = max(cost1, cost2), c2 = min(cost1, cost2);
        long long ans = 0;
        for (long long c = total; c >= 0; c -= c1) {
            ans += (c / c2) + 1;
        }
        
        return ans;
    }
};

// 啥？？？？？？我以為在及格邊緣，沒想到是 100%，轉型這麼花時間喔 ...
/*
Runtime: 15 ms, faster than 100.00% of C++ online submissions for Number of Ways to Buy Pens and Pencils.
Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Number of Ways to Buy Pens and Pencils.
*/
