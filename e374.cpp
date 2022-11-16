
// 2022.11.16

/*
binary search
*/

class Solution {
public:
    int guessNumber(int n) {
        unsigned l = 1, r = (unsigned)n + 1;
        while (l < r) {
            unsigned m = (l + r) / 2;
            int g = guess(m);
            if (g == 0)
                return m;
            else if (g == 1)
                l = m;
            else  // -1
                r = m;
        }
        return -1;  // not fund
    }
};
/*
Runtime: 2 ms, faster than 43.80% of C++ online submissions for Guess Number Higher or Lower.
Memory Usage: 6 MB, less than 22.94% of C++ online submissions for Guess Number Higher or Lower.
*/
