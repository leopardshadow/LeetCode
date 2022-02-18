
// 2022.2.18

/*
這星期好多寫過的，終於有一題新的了，感覺下次遇到寫過的可以從下面延伸題挑一題來寫，題數才會增加 XD
---
這題一看就給人 monotonic stack 的感覺w，但好不擅長這類型的題目 QQ
---
Nice explanation: https://leetcode.com/problems/remove-k-digits/discuss/607570/C%2B%2B-solution-8ms-with-detailed-explanation
*/

// 參考別人的寫法
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(const char &c : num) {
            while(ans.length() && c < ans.back() && k) {
                ans.pop_back();
                k--;
            }
            if(ans.length() || c != '0')
                ans.push_back(c);
        }
        while(k && ans.length()) {
            ans.pop_back();
            k--;
        }
            
        return (ans == "") ? "0" : ans;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove K Digits.
Memory Usage: 6.9 MB, less than 88.00% of C++ online submissions for Remove K Digits.
*/


/*
我的程式屍體
一開始覺得先把 0 處理掉比較好
但現在下面的寫法沒辦法處理 10002, k=2 這種情況
另外在 "stack" 部分，應該用 while 一層層砍上去
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k >= num.length())
            return "0";
        
        // deal with zeros
        // e.g.
        // Input: num = "10200", k = 1
        // Output: "200"
        int status = 1;
        while(status == 1) {
            status = 0;
            for(int i = 0; i < num.size(); i++) {
                if(num[i] == '0') {
                    if(k >= i) {
                        k -= i; 
                        num = num.substr(i+1);
                        status = 1;
                        break;
                    }
                    else {
                        status = 2;
                        break;
                    }
                }
                // no zero left
                status = 2;
            }
            if(status == 2)
                break;
        }
        
        if(k == 0)
            return num.length() > 0 ? num : "0";
        
        // mono stack
        string ans = num.substr(0, 1);
        int i;
        int size = 1;
        for(i = 1; i < num.length(); i++) {
            // discard one character
            if(num[i] < ans.back()) {
                ans.back() = num[i];
                k--;
            }
            else {
                ans.push_back(num[i]);
                size++;
            }
            
            if(size == num.length() - k)
                break;
                
            if(k == 0) {
                ans += num.substr(i+1);
                break;
            }
        }
        
        return ans;
    }
};
