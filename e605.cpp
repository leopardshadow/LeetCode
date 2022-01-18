
// 2022.1.18

/*
注意頭、尾 (可能是全 0，兩邊開 or 一編被封住) 和中間 (兩邊都封閉) 的行為會不一樣
---
雖然是 easy，但判斷條件寫不好，WA 了好幾次 QQ
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = 0;  // max flower allowed
        int cnt = 0;
        int i = 0;
        
        while(i < flowerbed.size() && flowerbed[i] == 0) {
            cnt++;
            i++;
        }
        if(i == flowerbed.size())  // all 0
            m += (cnt + 1) / 2;
        else
            m += cnt / 2;
        
        cnt = 0;
        
        for(; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0)
                cnt++;
            else {  // f == 1
                m += (cnt - 1) / 2;
                cnt = 0;
            }
        }
        
        m += cnt / 2;
        
        return m >= n;
    }
};

/*
Runtime: 40 ms, faster than 6.78% of C++ online submissions for Can Place Flowers.
Memory Usage: 20.3 MB, less than 20.95% of C++ online submissions for Can Place Flowers.
*/
