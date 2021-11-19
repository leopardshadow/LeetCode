// DP D2

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int cnt[3] = {1, 2, 0};
        n -= 2;
        while(n) {
            cnt[2] = cnt[0] + cnt[1];
            cnt[0] = cnt[1];
            cnt[1] = cnt[2];
            n--;
        }
        return cnt[2];
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
Memory Usage: 5.9 MB, less than 81.57% of C++ online submissions for Climbing Stairs.
*/
