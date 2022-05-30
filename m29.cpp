
// 2022.5.30

/*
寫除法不用到乘、除、mod 好麻煩喔 QQ
---
和我們一般在做直式除法一樣 a / b
會先把 b 移到 a 最近的位數（十進位下就只是往左邊寫，0 通常被省略）
如果這樣做的話好容易爆 range，把 a 往右移會比較簡單（多移的就變 0 而已，不會炸掉）
---
他要求只能在 32 bit 整數下做，原先給的是 integer
把 sign bit 拿掉後就不怕 b 在移動時超過 32 位（a 很大的時候可能會發生，b 再左移一步就超範圍）
更：不過如果是右移 a 就沒差
*/

// 我的作法 1：a / b 時把 b 往左移，好像怪怪的
/*
        unsigned ans = 0;
        int x = 0;
        
        while (a > (b << (x+1)))
            x++;
        
        for ( ; x >= 0; x--) {
            // cout << "x = " << x << " " << a << " " << (b << x);
            if (a >= (b << x)) {
                a -= (b << x);
                ans += (1 << x);
            }
            // cout << " : " << ans << endl;
        }
        while (a >= b) {
            a -= b;
            ans++;
        }
                
        // cout << a << endl;
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // -2^31 (INT_MIN) vs. 2^31 - 1 (INT_MAX)
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // negative quotient
        bool posi;
        if ((dividend ^ divisor) >> 31) {
            posi = false;
        }
        // positve quotient
        else {
            posi = true;
        }
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        
        unsigned int ans = 0;
        
        for (int i = 31; i >= 0; i--) {
            if ((a >> i) >= b) {
                ans |= (1 << i);
                a -= (b << i);
            }
        }
        
        return posi ? ans : -ans;
    }
};
/*
Runtime: 7 ms, faster than 27.04% of C++ online submissions for Divide Two Integers.
Memory Usage: 5.9 MB, less than 76.09% of C++ online submissions for Divide Two Integers.
*/
