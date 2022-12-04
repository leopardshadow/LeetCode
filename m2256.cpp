
// 2022.12.4

/*
略
*/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long sum = 0, curSum = 0;
        for (const int &n : nums)
            sum += n;
        int ans = 0, minDiff = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++) {
            curSum += nums[i];
            int p1 = (int)(1. * curSum / (i + 1));
            int p2 = (int)(1. * (sum - curSum) / (nums.size() - 1 - i));
            int diff = abs(p1 - p2);
            if (diff < minDiff) {
                ans = i;
                minDiff = diff;
            }
        }
        if ((int)(1. * sum / nums.size()) < minDiff)
            ans = nums.size() - 1;
        return ans;
    }
};
/*
Runtime: 261 ms, faster than 59.57% of C++ online submissions for Minimum Average Difference.
Memory Usage: 78.2 MB, less than 100.00% of C++ online submissions for Minimum Average Difference.
*/
