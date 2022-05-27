
// 2022.5.27

/*
用了 bit operation，但時間還是好久，看討論區有方法是不用迴圈或遞迴做的
---
不用遞迴或迴圈的作法
如果該位是 0，1 個步驟可以把他消滅
如果該位是 1，需要 2 個步驟 (先減一再除二) (除了最高位的 1 只要減一次)
以 14 (1110) 來說從高位到低位需要的步驟是 1 2 2 1，總和是 6
123 (1111011) 從高位到低位需要的步驟是 1 2 2 2 1 2 2，總和是 12
要找到最高位的 1 可以用一些 C++ 內建的函式
*/

class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num) {
            ans++;
            if (num & 1)  // odd
                num ^= 1;
            else  // even
                num >>= 1;
        }
        return ans;
    }
};
/*
Runtime: 4 ms, faster than 24.32% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
Memory Usage: 5.9 MB, less than 74.11% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
*/
