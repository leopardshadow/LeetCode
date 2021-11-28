/*
Key: 
```
n = n & (n - 1);
```
這會拿掉 n 最小的 1
如果不知道慢慢從 1 << 0, 1 << 1, 1 << 2, ... ,1 << 31 數也行
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            ans++;
            n = n & (n - 1);
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
Memory Usage: 5.9 MB, less than 47.57% of C++ online submissions for Number of 1 Bits.
*/
