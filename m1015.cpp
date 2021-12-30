
// 2021.12.30

/*
這題有一點 DP 的感覺
---
題目給的 hint 對我很關鍵
*******************
1111 = 111 * 10 + 1
*******************
所以如果我有 111 % k，把這個值 * 10 後 + 1 % k 就是 1111 % k 的值
---
因為上述操作會一直重複，如果出現之前曾經出現過的，就會開始循環，以 4 為例
  1 % 4 = 1
 11 % 4 = 3
111 % 4 = 3
    (之後都是 3)
    
所以如果發現開始循環了，那就不可能用 1 組成 k 的倍數
---
下面的 code 有可以優化空間的地方，因為每次都只會 depend on 前一個，所以不用把過程全部存起來
只需要有一個 int cnt 存目前長度就好
*/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
                        
        vector<int> rem;
        vector<bool> appear(k, false);
        
        rem.push_back(1);
        
        while(rem.back() % k != 0) {
            rem.push_back((rem.back() * 10 + 1) % k);
            if(appear[ rem.back() ])
                return -1;
            appear[ rem.back() ] = true;
        }
        
        return rem.size();
    }
};

/*
Runtime: 9 ms, faster than 34.45% of C++ online submissions for Smallest Integer Divisible by K.
Memory Usage: 7.8 MB, less than 25.21% of C++ online submissions for Smallest Integer Divisible by K.
*/




//******************************************************************************//
// 優化版

class Solution {
public:
    int smallestRepunitDivByK(int k) {
                        
        int r = 1, cnt = 1;
        vector<bool> appear(k, false);
        
        appear[r] = true;
        
        while(r % k != 0) {
            cnt++;
            r = (r * 10 + 1) % k;
            if(appear[ r ])
                return -1;
            appear[ r ] = true;
        }
        return cnt;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Integer Divisible by K.
Memory Usage: 6.4 MB, less than 27.73% of C++ online submissions for Smallest Integer Divisible by K.
*/
