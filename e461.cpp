class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        // cnt 1s of x
        int cnt = 0;
        while(x) {
            cnt++;
            x = x & (x - 1);
        }
        return cnt;
    }
};


/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
Memory Usage: 6 MB, less than 24.75% of C++ online submissions for Hamming Distance.
*/
