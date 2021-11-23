// Google 

/*
Hint.
他的提示說的差不多了 XD
The minimum difference possible is is obtained by removing 3 elements between the 3 smallest and 3 largest values in the array.
但我是看了提示才會的 QQ
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int n = nums.size();
        ans = min(ans, nums[n-4] - nums[0]);
        ans = min(ans, nums[n-3] - nums[1]);
        ans = min(ans, nums[n-2] - nums[2]);
        ans = min(ans, nums[n-1] - nums[3]);
        return ans;
    }
};

/*
Runtime: 80 ms, faster than 92.08% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
Memory Usage: 35.3 MB, less than 51.17% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
*/
