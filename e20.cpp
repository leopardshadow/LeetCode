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