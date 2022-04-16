
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
