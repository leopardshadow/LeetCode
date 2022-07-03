
// 2022.7.3

/*
好酷的解法！！
---
這個週末都在編 kernel，偷懶一下 ><
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int down = 1, up = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1])
                up = down + 1;
            else if (nums[i] < nums[i-1])
                down = up + 1;
        }
        return max(up, down);
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wiggle Subsequence.
Memory Usage: 7 MB, less than 95.65% of C++ online submissions for Wiggle Subsequence.
*/
