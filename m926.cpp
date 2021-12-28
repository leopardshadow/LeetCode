
//******************************************************************************//
// 12.28 - 1 Day Before A VO
// 剛好湊個 240 題，明天 +u

/*
題目要求 monotone increasing，string s 又只有 0 和 1
所以要翻幾次才能讓他是 monotone increasing 其實就是在問
從頭把幾個 1 翻成 0，以及從尾把幾個 0 翻成 1 可以讓他成為 monotone increasing
---
我的作法是找到那個 0/1 的交界處，他往前全部都是 0，往後都 1，要做到這樣需要翻幾次
---
包含自己 / 不包含自己的差別是先存再 +1 還是先 +1 才存
---
這題的 edge case (變成全 0 / 全 1) 讓我吃了一個 WA
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        vector<int> cnt0(s.length()),
                    cnt1(s.length());
        
        int cnt = 0;
        
        int ans = INT_MAX;
        
        // 包含那位及往前有幾個 1 (1 需要被翻成 0)
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1')
                cnt++;
            cnt1[i] = cnt;
        }
        
        // for all 0
        ans = min(ans, (int)s.length() - cnt);
        
        // all 0
        if(cnt == s.length())
            return 0;
        
        cnt = 0;
        // 往後有幾個 0 (不包含自己)
        for(int i = s.length() - 1; i >= 0; i--) {
            cnt0[i] = cnt;
            if(s[i] == '0')
                cnt++;
        }
        
        // for all 1
        ans = min(ans, (int)s.length() - cnt);

        
        for(int i = 0; i < s.length(); i++)
            ans = min(ans, cnt1[i] + cnt0[i]);
        return ans;
    }
};

/*
Runtime: 48 ms, faster than 16.45% of C++ online submissions for Flip String to Monotone Increasing.
Memory Usage: 19.9 MB, less than 22.71% of C++ online submissions for Flip String to Monotone Increasing.
*/
