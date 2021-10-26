/*
    1 1 ------ carry
  0 1 1 0 1 -- a
+ 0 0 1 1 0 -- b
------------
  1 0 0 1 1     
  
  
  -1     1 1 1 1 1 ... 1 
   1  +  0 0 0 0 0 ... 1
---------------------------
       1 0 0 0 0 0 ... 0
---------------------------
steps: 1 1 1 1 ... 1 1 0 (xor)
       0 0 0 0 ... 0 1 0 (carry)
---------------------------
       1 1 1 1 ... 1 0 0
       0 0 0 0 ... 1 0 0
---------------------------
       1 1 1 1 ... 0 0 0
       0 0 0 ... 1 0 0 0
*/
// class Solution {
// public:
//     int getSum(int a, int b) {
//         if(!a) return b;
//         // carry, sum
//         return getSum((int)((unsigned)(a&b)<<1), a^b);
//     }
// };

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Two Integers.
Memory Usage: 6 MB, less than 29.60% of C++ online submissions for Sum of Two Integers.
*/



class Solution {
public:
    int getSum(int a, int b) {
        int carry, sum;
        do {
            carry = (int)((unsigned)(a&b)<<1);
            sum = a ^ b;
            a = carry;
            b = sum;
        } while(a);
        return b;
    }
};