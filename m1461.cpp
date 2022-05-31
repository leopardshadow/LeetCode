
// 2022.5.31

/*
我類似 sliding window 的感覺來寫這題
要找到所有長度 k 的 substring，每個 substring 大部分都一樣，只差一點點，不用全部重算 (雖然感覺這題全部重算也會過(?))
---
題目問所有長度為 k 的 binary code 是否都有在 s 裡面
把數字用二進位表示就是在問 [0, 1 << k) 這 2^k 個二進位字串有沒有都在 s 裡
---
接下來我們把 s 所有長度為 k 的 substring 抓出來
看 [0, 1 << k) 裡面有沒有數字不在 長度為 k 的 substring 裡就完工了
---
快速判斷在不在裡面我是用 map，但其實用一維陣列比較好（size = 2^k）
---
num &= (~(1 << k)); --> 清零（從最低位開始數的）第 k 個 bit
e.g. k = 2, 1 << k = 0000 0100, ~ 後是 1111 1011
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if (s.length() < k)
            return false;
        
        int num = 0;
        for (int i = 0; i < k; i++) {
            num <<= 1;
            if (s[i] == '1')
                num = num | 1;
        }
        
        set<int> ns;
        ns.insert(num);
        
        for (int i = k; i < s.length(); i++) {
            num <<= 1;
            num &= (~(1 << k));  // clear the k.th bit (count from LSB)
            if (s[i] == '1')
                num = num | 1;
            ns.insert(num);
        }
        
        for (int i = 0; i < (1 << k); i++) {
            if (!ns.count(i))
                return false;
        }
        return true;
    }
};
/*
Runtime: 615 ms, faster than 34.59% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
Memory Usage: 44.3 MB, less than 67.61% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
*/
