// DP D2

/*
有個小細節要特別注意的是，這裡的爬到 top 是陣列外，
所以要加 1
*/

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int> table(cost.size() + 1, 0);
//         for(int i = 2; i < cost.size() + 1; i++) {
//             table[i] = min(table[i-1] + cost[i-1],
//                            table[i-2] + cost[i-2]);
//         }
//         return table.back();
//     }
// };

/*
10. 15. 20. 30
c2. c1. cc. 
    c2. c1. cc. 
*/
/* 
這裡是上面拿掉多餘的紀錄的版本
因為只和前兩個有關，所以不用存那麼多
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int curCost1 = 0, curCost2 = 0;
        int curCost;
        for(int i = 2; i < cost.size() + 1; i++) {
            curCost = min(curCost1 + cost[i-1],
                          curCost2 + cost[i-2]);
            curCost2 = curCost1;
            curCost1 = curCost;
        }
        return curCost;
    }
};

/*
Runtime: 4 ms, faster than 90.46% of C++ online submissions for Min Cost Climbing Stairs.
Memory Usage: 13.7 MB, less than 76.61% of C++ online submissions for Min Cost Climbing Stairs.
*/


// 2022.7.10
