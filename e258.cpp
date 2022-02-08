
// 2022.2.8

/*
這題雖然是 easy，卻有五個 hints!!
---
最直接的解法就是照著他的敘述寫
---
但也可以用數學的方式說明答案會和 mod 9 有關係
就像小時候判斷一個數是不是 3 / 9 的倍數一樣作法
  10 mod 9 = 1
 100 mod 9 = 1
1000 mod 9 = 1
...
但是要注意
9 mod 9 = 0
18 mod 9 = 0
但是如果一開始的數字不為 0，最後結果一定不會是 0，數字不會憑空消失
這點要特別處理
---
好酷的一行解
```
return 1 + (num - 1) % 9;
```
*/

class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while(sum > 9) {
            num = sum;
            sum = 0;
            while(num) {
                sum += num % 10;
                num /= 10;
            }
        }
        return sum;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Digits.
Memory Usage: 6 MB, less than 25.37% of C++ online submissions for Add Digits.
*/


// 可能用到兩次 mod 所以比較慢 (?)

class Solution {
public:
    int addDigits(int num) {
        if(num <= 9)
            return num;
        return (num % 9 == 0) ? 9 : num % 9;
    }
};

/*
Runtime: 8 ms, faster than 8.74% of C++ online submissions for Add Digits.
Memory Usage: 5.7 MB, less than 95.57% of C++ online submissions for Add Digits.
*/
