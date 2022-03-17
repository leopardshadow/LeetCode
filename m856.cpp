
// 2022.3.17

/*
這週是 stack 週，開始害怕 DP 週和 monotonic stack 週了XD
---
我的想法是遇到 () 比較簡單，stack 可以直接放進 1 --> 兩個寫法差在如何處理這件事
如果遇到 (( 就代表之後有人要被乘 2
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' && s[i+1] == ')') {  // watch out the range
                st.push(1);
                i += 1;
            }
            else if(s[i] == '(')
                st.push(-1);  // denotes '('
            else if(s[i] == ')') {
                int cur = 0;
                while(st.size() > 0 && st.top() != -1) {
                    cur += st.top();
                    st.pop();
                }
                st.pop();  // pop -1
                st.push(cur * 2);
            }
        }
        int ans = 0;
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 21.82% of C++ online submissions for Score of Parentheses.
Memory Usage: 6.2 MB, less than 8.12% of C++ online submissions for Score of Parentheses.
*/



class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(const char &c : s) {
            if(c == '(') {
                st.push(-1);  // actually, I want to push 0.5 for general
            }
            else {
                if(st.top() == -1)
                    st.top() = 1;
                else {
                    int cur = 0;
                    while(st.size() > 0 && st.top() != -1) {
                        cur += st.top();
                        st.pop();
                    }
                    st.pop();  // pop -1
                    st.push(cur * 2);
                }
            }
        }
        int ans = 0;
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;

    }
};

/*
Runtime: 2 ms, faster than 37.38% of C++ online submissions for Score of Parentheses.
Memory Usage: 6.3 MB, less than 8.12% of C++ online submissions for Score of Parentheses.
*/
