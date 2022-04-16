
// Biweekly Contest 76

/*
easy, BJ4
*/

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX;
        for (int n : nums) {
            if (abs(n) < abs(ans))
                ans = n;
            else if (abs(n) == abs(ans))
                ans = max(ans, n);
        }
        return ans;
    }
};
/*
Runtime: 19 ms, faster than 100.00% of C++ online submissions for Find Closest Number to Zero.
Memory Usage: 19.6 MB, less than 42.86% of C++ online submissions for Find Closest Number to Zero.
*/
