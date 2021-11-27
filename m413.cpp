
/*
寫出來可以找到規律
1 2 3 -> 1 1 -> Ans: 1
1 2 3 4 -> 1 1 1 -> Ans : 3 = 1 + 2
1 2 3 4 5 -> 1 1 1 1 -> Ans: 6 = 1 + 2 + 3

*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        int ans = 0;
        int prev = nums[0] - nums[1];
        int curLen = 1;
        for (int i = 2; i < nums.size(); i++) {
            int cur = nums[i-1] - nums[i];
            if (cur == prev) {
                curLen++;
                //
                ans += (curLen - 1);
            }
            else {
                curLen = 1;
            }
            prev = cur;
        }
        return ans;
    }
};

/*
Runtime: 3 ms, faster than 62.01% of C++ online submissions for Arithmetic Slices.
Memory Usage: 7.4 MB, less than 15.64% of C++ online submissions for Arithmetic Slices.
*/
