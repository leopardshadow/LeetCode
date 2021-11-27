/* 
binary serach 的變形，要注意的是 int 的上限
在算 (m+1) * (m+1) 時，如果 x 是 2^31 - 1 可能就會超過 int 的表示範圍
所以這裡我用 unsigned long lone
*/

class Solution {
public:
    int mySqrt(int x) {
        unsigned long long l = 0, r = 1 << 16, m;
        while(l <= r) {
            m = (l + r) / 2;
            if(m * m <= x && (m+1) * (m+1) > (unsigned long long)x)
                return m;
            else if(m * m < x)
                l = m + 1;
            else
                r = m -1;
        }
        return -1;  // never returns this
    }
};

/*
Runtime: 3 ms, faster than 57.50% of C++ online submissions for Sqrt(x).
Memory Usage: 6 MB, less than 25.27% of C++ online submissions for Sqrt(x).
*/
