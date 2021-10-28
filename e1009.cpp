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