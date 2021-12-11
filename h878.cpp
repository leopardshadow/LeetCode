/*
像這種 Nth 的題目有時候都是用 binary search，之前遇到幾題也是，重點是找出數學式，寫出回傳值和 n 的關係
看了一下討論區，回傳的數字 x 要滿足 x / a + x / b - x / lcm(a, b) == n
可以用排容去想這是式子怎麼來的

有了這個式子就可以開始 binary search 了，要特別注意上、下界如何設
下界: n = 1 --> x = min(a, b)
上界: 只要設得夠大就行，這題可以設成 LONG_LONG_MAX 或 min(a, b) * n 都行

log2 ~ 0.3010

unsigned int - 4B - 最大到 2^32，0.3 * 32 = 9.6 ，可以表示到部分 10 位的數字
unsined long - 8B - 最大到 2^64，0.3 * 64 = 19.2，可以表示到部分 20 位的數字
  long long  - 8B - 最大到 2^63，0.3 * 64 = 18.9，可以表示到部分 19 位的數字

---
一開始這題的感覺和找第幾個 2, 3 或 5 的倍數那題好像，只是現在改成 a, b，而且數字可能會很大

*/


class Solution {
    int gcd(int a, int b) {
        int t;
        while(a && b) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    int lcm(int a, int b) {
        int g = gcd(a, b);
        return (a / g) * b;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {

        long long l = min(a, b),
                  r = (long long)min(a,b) * n,
                  lcm_ab = lcm(a, b),
                  m, check;
        
        while(l <= r) {
            
            m = l + (r - l) / 2;
            
            check = m/a + m/b - m/lcm_ab;
            
            if(check == n && (m % a == 0 || m % b == 0))
                return m % 1000000007;
            else if(check < n)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1; // never returns this
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Nth Magical Number.
Memory Usage: 6 MB, less than 30.46% of C++ online submissions for Nth Magical Number.
*/


//---


// class Solution {
//     int gcd(int a, int b) {
//         int t;
//         while(a && b) {
//             t = b;
//             b = a % b;
//             a = t;
//         }
//         return a;
//     }
//     int lcm(int a, int b) {
//         int g = gcd(a, b);
//         reutnr (a / g) * b;
//     }
// public:
//     int nthMagicalNumber(int n, int a, int b) {
        
//         unsigned int as = 0,  // a 2a 3a 4a ...
//                      bs = 0;  // b 2b 3b 4b ...                
//         as = 0;
//         bs = 0;
                
//         int i = 1;
        
//         while(i <= n) {
            
//             if(as < bs) {
//                 as = (as + a) % 1000000007;
//             }
//             else if(as == bs) {
//                 as = (as + a) % 1000000007;
//                 bs = (bs + b) % 1000000007;
//             }
//             else {
//                 bs = (bs + b) % 1000000007;
//             }
            
//             i++;
//         }
//         return min(as, bs);
//     }
// };

