// 2021.12.18

/*
其實這題有點搞不太懂為什麼 digits 要給 string，給個 char 或 int 不是很好嗎，不用自己 stoi 轉換
---
明天寫筆記，先睡了 大概花 30 分鐘寫完這題
*/

class Solution {
    
    // 1 0
    // 0 1 2
    // 5 4
    int qq(int i, vector<string>& digits, vector<int> &ns) {
        if(i == ns.size())
            return 1;
        
        int cnt = 0;
        int ret = 0;
        
        for(int j = 0; j < digits.size(); j++) {
            
            if(stoi(digits[j]) < ns[i])
                cnt++;
            
            else if(stoi(digits[j]) == ns[i])
                ret += qq(i + 1, digits, ns);
            
            else {
                break;
            }
            
        }
        
        ret += cnt * (int)pow(digits.size(), (ns.size() - i - 1));
        
        return ret;
    }
    
    
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        int d = digits.size();
        
        vector<int> dp(1, 1);
        
        int ans = 0;
        
        // 123 --> [1 2 3]
        vector<int> ns;
        int m = 0;
        while(n) {
            ns.insert(ns.begin(), n % 10);
            n /= 10;
            dp.push_back(d * dp.back());
            m++;
        }
                
        // < m
        for(int i = 1; i < m; i++) {
            dp[i] = d * dp[i-1];
            ans += dp[i];
        }
        
        
        
        // e.g. 3 7 9
        // 1 2 3 4 5 6 7 8 9
        //-------------------
        // 0 0 0 1 1 1 1 2 3
        // 紀錄有幾個人「小於」(不算等於) 這個數字
        
        // int table[10] = {0};
        // for(int i = 1; i <= 9 ; i++) {
        //     for(int j = 0; j < digits.size(); j++) {
        //         int dd = stoi(digits[j]);
        //         if(table[i] >= dd)
        //             table[i]++;
        //     }
        // }
        
        // == m
        // int t = 1;
        // for(int i = 0; i < ns.size(); i++) {
        //     int cnt = 0;
        //     for(int j = 0; j < digits.size(); j++) {
        //         int dd = stoi(digits[j]);
        //         if(dd <= ns[i]) {
        //             cnt += 1;
        //         }
        //     }
        //     t *= cnt;
        // }
        
        
        ans += qq(0, digits, ns);
        
        return ans;
    }
};


/*
Runtime: 3 ms, faster than 53.09% of C++ online submissions for Numbers At Most N Given Digit Set.
Memory Usage: 8.4 MB, less than 5.67% of C++ online submissions for Numbers At Most N Given Digit Set.
*/
