// DP D1

// Tribonacci
/*
  0.     1.     2
 a_i   a_i+1  a_i+2
a_i+1  a_i+2  a_i+3
*/


class Solution {
public:
    int tribonacci(int n) {
        int temp, iter[4] = {0, 1, 1};
        if(n < 3) return iter[n];
        n = n - 2;
        while(n) {
            temp = iter[0] + iter[1] + iter[2];
            iter[0] = iter[1];
            iter[1] = iter[2];
            iter[2] = temp;
            n--;
        }
        return iter[2];
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
Memory Usage: 5.9 MB, less than 80.44% of C++ online submissions for N-th Tribonacci Number.
*/
