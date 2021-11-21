// DP D4

/*
這題算是 55. Jump Game 的變形
只是 55. 算的是可不可以到最後一個，而這題則是問最小步數
我是用兩層迴圈去繞，更新從 i 往後 1~ nums[i] 的最小步數，但這樣比較慢
*/

/*
i: 0 1 2 3 4
n: 2 3 1 1 4
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxIndex = 0;
        vector<int> minSteps(nums.size(), 100000);
        minSteps[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int step = 1; step <= nums[i] && i + step < nums.size(); step++) {
                minSteps[i + step] = min(minSteps[i] + 1, minSteps[i + step]);
            }
        }
        return minSteps.back();
    }
};

/*
Runtime: 404 ms, faster than 17.63% of C++ online submissions for Jump Game II.
Memory Usage: 17.1 MB, less than 14.21% of C++ online submissions for Jump Game II.
*/
