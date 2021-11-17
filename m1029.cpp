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
