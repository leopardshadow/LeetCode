/*
00000010100101000001111010011100
a0 <--> a31
a1 <--> a30
    ...
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int b = 0; b < 32; b++) {
           ans |= ((n >> b) & 1) << (31 - b);
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Bits.
Memory Usage: 5.7 MB, less than 96.51% of C++ online submissions for Reverse Bits.
*/