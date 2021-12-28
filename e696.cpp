

/*
感覺這題是 easy 中需要思考的 XD
---
暴力解很容易，但有更快的作法
---
我的想法是把連續 0/1 的個數抓出來
以 Example 1 的 00110011 來說會是
2 2 2 2
而答案是相鄰兩個之間比較小的和：min(2, 2) + min(2, 2) + min(2, 2) = 6
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        
        // 010101
        vector<int> cnt;
        
        // 為了不特別處理特殊 case push 的 0
        cnt.push_back(0);
        
        for(char c : s) {
            if(c == '0') {
                if(cnt.size() % 2)  // 0, 010
                    cnt.back()++;
                else
                    cnt.push_back(1);
            }
            else {  // 1
                if(cnt.size() % 2)  // 0, 010
                    cnt.push_back(1);
                else
                    cnt.back()++;
            }
        }
        
        if(*cnt.begin() == 0)
            cnt.erase(cnt.begin());
        
        int ans = 0;
        
        for(int i = 1; i < cnt.size(); i++)
            ans += min(cnt[i-1], cnt[i]);
        
        return ans;
    }
};
