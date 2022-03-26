/*
這題是玩 Leetcode online assessment 的第二題
題目敘述 <略>
他的重點在於，不論到 A 到 B，都會有開銷，重點是差了多少，
因此我拿 a - b 排序，最小的 n 個選擇到 a，其他 n 個就選擇到 b
直接看個例子吧
 a.    b. 
----  ----
 10 -  20 = -10
 30 - 200 = -170
400 -  50 = 350
 30 - 20 =  10
 
 根據 a, b 相減之後的結果分出兩邊，上半部是 a - b 比較小的，也就是 a 比 b 便宜
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        for(int i = 0; i < n; i++) {
            costs[i][0] = costs[i][0] - costs[i][1];
        }
        
        sort(costs.begin(), costs.end());
        
        int ans = 0;
        for(int i = 0; i < n / 2; i++) {
            ans = ans + costs[i][0] + costs[i][1];
        }
        for(int i = n / 2; i < n; i++) {
            ans = ans + costs[i][1];
        }
        return ans;
    }
};


/*
Runtime: 4 ms, faster than 82.52% of C++ online submissions for Two City Scheduling.
Memory Usage: 7.8 MB, less than 73.95% of C++ online submissions for Two City Scheduling.
*/


// 2022.3.25
// submit the smae code ><

/*
後來想想這題有種比較利益的感覺 (?)
A 一小時能捕 6 隻魚或採 10 顆水果 ; B 一小時能能捕 2 隻魚或採 3 顆水果。
雖然 A 不管在捕魚或採水果都能屌打 B，但比較利益告訴我們 A 如果和 B 合作，他們兩人合作的產出還是會比兩人單獨自幹總和多。
A 可以專注在自己的專頁上
---
這裡也是同樣的感覺，不能直接依數字本身來比
*/

/*
Runtime: 3 ms, faster than 90.96% of C++ online submissions for Two City Scheduling.
Memory Usage: 7.8 MB, less than 94.48% of C++ online submissions for Two City Scheduling.
*/
