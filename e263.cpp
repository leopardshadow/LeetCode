
// 2022.11.18

class Solution {
public:
    bool isUgly(int n) {
        if (n == 0)
            return false;
        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;
        return n == 1;
    }
};
/*
Runtime: 6 ms, faster than 26.78% of C++ online submissions for Ugly Number.
Memory Usage: 5.9 MB, less than 19.97% of C++ online submissions for Ugly Number.
*/
