
// 2022.8.24

/*
找了個 log 的寫法，好酷！
判斷 n = 3 ^ x 的 x 是不是整數
---
Note. 
判斷 double 是不是整數的用法可以用 ceil(x) == floor(x)
也可以用 modf ! (https://en.cppreference.com/w/cpp/numeric/math/modf)
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        double d = log10(n) / log10(3);
        return ceil(d) == floor(d);
    }
};
/*
Runtime: 50 ms, faster than 15.85% of C++ online submissions for Power of Three.
Memory Usage: 6.1 MB, less than 7.72% of C++ online submissions for Power of Three.
*/
