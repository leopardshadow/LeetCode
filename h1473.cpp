
// 2022.7.8

/*
看著解答把 dp array 訂出來後就比較有感覺了，但這才是難的點啊 QQQ
*/

class Solution {
    int dp[101][101][21];
    const int MAX_COST = 100000000; // indicates impossible
    int findMinCost(vector<int>& houses, vector<vector<int>>& cost, int targCnt, int curIdx,
                    int cnt, int prevColor) {
        
        if (curIdx == houses.size())
            return cnt == targCnt ?  0 : MAX_COST;
        
        if (cnt > targCnt)
            return MAX_COST;
        
        if (dp[curIdx][cnt][prevColor] != -1)
            return dp[curIdx][cnt][prevColor];
        
        int minCost = MAX_COST;
        
        if (houses[curIdx]) {  // already painted
            int newCnt = cnt + (houses[curIdx] != prevColor);
            minCost = findMinCost(houses, cost, targCnt, curIdx+1, newCnt, houses[curIdx]);
        }
        else {
            for (int i = 1; i <= cost[0].size(); i++) {  // traverse every color
                int newCnt = cnt + (i != prevColor);
                minCost = min(minCost,
                              findMinCost(houses, cost, targCnt, curIdx+1, newCnt, i) + cost[curIdx][i-1]);
            }
        }
        return dp[curIdx][cnt][prevColor] = minCost;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = findMinCost(houses, cost, target, 0, 0, 0);
        return ans == MAX_COST ? -1 : ans;
    }
};
/*
Runtime: 82 ms, faster than 83.78% of C++ online submissions for Paint House III.
Memory Usage: 10.7 MB, less than 92.29% of C++ online submissions for Paint House III.
*/
