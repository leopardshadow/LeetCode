class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
        for(int i =0; i < s.length(); i++) {
            if(s[i] == '(' ||
               s[i] == '[' ||
               s[i] == '{')
                st.push(s[i]);
            // popping from an empty stack leads to error...
            else if(st.empty())
                return false;
            else if(s[i] == ')') {
                c = st.top();
                st.pop();   
                if(c != '(') return false;
            }
            else if(s[i] == ']') {
                c = st.top();
                st.pop();  
                if(c != '[') return false;
            }
            else if(s[i] == '}') {
                c = st.top();
                st.pop();   
                if(c != '{') return false;
            }

        }
        return st.empty();
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.3 MB, less than 50.38% of C++ online submissions for Valid Parentheses.
*/



//******************************************************************************//
// 2022.3.13

/*
這次和上次一樣，一個 WA，一個 RE 後才 AC
太趕了，感覺犯的錯誤和之前一樣 ...
WA 是因為把 string 全部走過一次後可能 stack 還有剩
RE 則是因為 stack 可能是空的，此時遇到右括號不能 pop 東西
---
在 pop 誰的部分，我用了 map 去找，省掉三段類似的判斷
原本以為左右括號的 ASCII 編碼應該都只差 1 在隔壁，沒想到有些是有些不是 () ... [\] ... {|}
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        for(const char &c : s) {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else {
                if(st.size() && st.top() == m[c])
                    st.pop();
                else
                    return false;
            }
        }
        return st.size() == 0;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.4 MB, less than 10.36% of C++ online submissions for Valid Parentheses.
*/
