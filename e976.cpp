
// 2022.10.12

/*
形成三角形的條件是
* a + b > c > | a - b| (a, b, c 任意) OR
* a + b > c (c > a && c > b)
這裡用到的是第二項，先排序後條件就自動達成了，只要管一個不等式
因為希望周長最大，所以選最大的 c，看有沒有對應的 a b (greedy 得選最大)
如果不符合，那就把 c 調小一點點試試看，找不到就一直調小 c
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 1; i >= 2; i--) {
            if (nums[i] < nums[i-1] + nums[i-2])
                return nums[i] + nums[i-1] + nums[i-2];
        }
        return 0;
    }
};
/*
Runtime: 95 ms, faster than 15.52% of C++ online submissions for Largest Perimeter Triangle.
Memory Usage: 21.9 MB, less than 71.51% of C++ online submissions for Largest Perimeter Triangle.
*/
