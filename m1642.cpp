
// 2022.6.21 夏至

/*
heights[i-1] --> hieghts[i] 可能要往上爬（需要梯子和磚頭）或往下跳（什麼都不需要）
這些往上爬的動作，greedy 來想，會想讓大的跳躍用梯子，小的用磚塊，這樣比較不容易操作
再走的時候決定大小 -> priority queue 存用 ladder 跳的，pq 內留大的，小的丟給 bricks 去處理
而且丟給 bricks 處理後他就不會再丟回 ladder 了，因為前面都有更大的卡著
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;  // pq stores the heights diff using ladders
        int sum = 0;
        for (int i = 1; i < heights.size(); i++) {
            
            if (heights[i-1] >= heights[i])  // donot need ladders nor bricks
                continue;
            
            int diff = heights[i] - heights[i-1];
            
            pq.push(diff);
            if (pq.size() > ladders) {
                int b = pq.top();
                pq.pop();
                sum += b;
                if (sum > bricks)  // cannot reach i, furthest reachable is (i-1)
                    return i - 1;
            }
        }
        return heights.size() - 1;  // can reach the end
    }
};
/*
Runtime: 130 ms, faster than 76.51% of C++ online submissions for Furthest Building You Can Reach.
Memory Usage: 53.8 MB, less than 42.34% of C++ online submissions for Furthest Building You Can Reach.
*/
