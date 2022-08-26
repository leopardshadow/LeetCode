
// 2022.8.26

/*
列舉 n 的各種排列組合或是 power of 2 的排列組合
*/

class Solution {
    bool isPerm(int a, int b) {
        int x[10] = { 0 }, y[10] = { 0 };
        while (a) {
            x[a % 10]++;
            a /= 10;
        }
        while (b) {
            y[b % 10]++;
            b /= 10;
        }
        for (int i = 0; i < 10; i++)
            if (x[i] != y[i])
                return false;
        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<int> twoSet;
        for (int i = 0; i < 31; i++) {
            int x = 1 << i;
            if (isPerm(x, n))
                return true;
        }
        return false;
    }
};
/*
Runtime: 4 ms, faster than 61.58% of C++ online submissions for Reordered Power of 2.
Memory Usage: 6 MB, less than 83.90% of C++ online submissions for Reordered Power of 2.
*/
