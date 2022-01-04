class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while(mask < n) {
            mask = (mask << 1) | 1;
        }
        return n ^ mask;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complement of Base 10 Integer.
Memory Usage: 5.9 MB, less than 87.42% of C++ online submissions for Complement of Base 10 Integer.
*/

//******************************************************************************//
// 2022.1.4

// 有夠偷懶，題目都寫了，和 476. Number Complement 一樣，但 476 在 2021.12.27 才出過

/*
12.27 我是用 while((~mask) & num) 作為判斷條件
用 while(mask < n) 比較漂亮w
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while(mask < n)
            mask = mask << 1 | 1;
        return mask & (~n);
    }
};


// 明明就一樣的寫法，上次是 100%，這次卻變 12.33%
/*
Runtime: 2 ms, faster than 12.33% of C++ online submissions for Complement of Base 10 Integer.
Memory Usage: 6 MB, less than 31.93% of C++ online submissions for Complement of Base 10 Integer.
*/
