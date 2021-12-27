
// 2021.12.27

/*
這題做 bitwise not 的部分不難，但是要注意 leading zero 的部分
可以用 loop 去找或用 log2 去得到 num 的範圍
我對 cmath 不熟就用 bitwise 的操作
---
先找到對應的 mask
101
111
---
10111
11111
---
接著把 num 取 bitwise not 後 & mask 就是答案了
*/

class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        while((~mask) & num)
            mask = (mask << 1) | 1;
        return (~num) & mask;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number Complement.
Memory Usage: 5.9 MB, less than 40.00% of C++ online submissions for Number Complement.
*/
