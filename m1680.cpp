
// 2022.9.23

/*
simulation!
*/

class Solution {
public:
    int concatenatedBinary(int n) {
        unsigned long i = 1, ans = 0;
        for (unsigned long x = n; x >= 1; x--) {
            unsigned long y = x;
            while (y) {
                if (y & 1)
                    ans += i;
                y >>= 1;
                i = (i << 1) % 1000000007;
                ans %= 1000000007;
            }
        }
        return ans;
    }
};
/*
Runtime: 297 ms, faster than 35.87% of C++ online submissions for Concatenation of Consecutive Binary Numbers.
Memory Usage: 5.8 MB, less than 82.61% of C++ online submissions for Concatenation of Consecutive Binary Numbers.
*/
