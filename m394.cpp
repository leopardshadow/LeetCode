// 2021.12.19

/*
說到括弧閉合、匹配的題目很自然就想到 stack
---
但是這種不能單純用 FSM 或 RE 解，一定需要另一個東西來裝 (我這裡用 stack)
push-down automata (?)

分成幾種情況：
* 遇到 [：把數字 push 進 stack，以及 push 進空字串
* 遇到 ]：pop 兩個字串出來，一個是數字，一個是一般字串，要把那個字串複製 n 次往 stack 最後一個元素塞!!
* 遇到數字：可能有兩種情況 - 第一個數字 (n = -1) 或他不是第一位 (例如 123 的 2 和 3)
* 其他：往 stack 最後一個元素塞
*/

class Solution {
public:
    string decodeString(string s) {
        
        vector<string> st;
        st.push_back("");
        int n = -1;
        
        int i = 0;
        
        while(i < s.length()) {
            if(s[i] == '[') {
                st.push_back(to_string(n));
                n = -1;
                st.push_back("");
            }
            else if(s[i] == ']') {
                string t = st.back();
                st.pop_back();
                
                int m = stoi(st.back());
                st.pop_back();
                string toPush = "";
                for(int mm = 0; mm < m; mm++)
                    toPush += t;
                
                // merge!
                st.back() += toPush;
                                    
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                if(n == -1)
                    n = s[i] - '0';
                else
                    n = 10 * n + s[i] - '0';
            }
            else {
                st.back() += s.substr(i, 1);
            }
            i++;
        }
        
        string ans = "";
        for(string s : st)
            ans += s;
        
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
Memory Usage: 6.7 MB, less than 20.45% of C++ online submissions for Decode String.
*/
