
// 2022.1.14

/*
基本上就是照著他說的步驟一步一步做
---
因為他有可能超過 INT_MAX 或小於 INT_MIN，所以我用 long 去存
但也怕他超過 long 可以表達的範圍，所以在字串轉換成數字的迴圈裡一直去檢查
---
neg = 0(-) / 1(+)
這裡是我覺得我設計很酷的一個點 XD
因為在轉換過程只想用加的，所以如果
知道他是正數，且超過 2^31 - 1 或
知道他是負數，且超過 2^31
就要 clamp 成 INT_MAX / INT_MIN
可以發現上面負數的範圍比正數的範圍多 1，剛好就是 neg 的值
*/

class Solution {
public:
    int myAtoi(string s) {
        
        long ans = 0;
        int neg = 0;
        
        // 1. remove leading whitespaces
        while(s.length() && s[0] == ' ')
            s = s.substr(1);
        
        // 2. determine the sign
        if(s[0] == '+')
            s = s.substr(1);
        else if(s[0] == '-') {
            s = s.substr(1);
            neg = 1;
        }
        
        // 3. determine the number part & ignore the rest
        int len = 0;
        while(s[len] <= '9' && s[len] >= '0')
            len++;
        s = s.substr(0, len);
        
        // 4. convert string to interger
        // 5. clamp
        for(int i = 0; i < s.length(); i++) {
            ans = 10 * ans + s[i] - '0';
            if(ans > (long)INT_MAX + neg - 1) {
                return neg == 0 ? INT_MAX : INT_MIN;
            }
        }
        
        if(neg)
            ans = -ans;
        
        return (int)ans;
    }
};

/*
Runtime: 4 ms, faster than 61.55% of C++ online submissions for String to Integer (atoi).
Memory Usage: 7.2 MB, less than 14.31% of C++ online submissions for String to Integer (atoi).
*/
