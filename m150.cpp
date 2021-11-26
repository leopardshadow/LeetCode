// RPN
// stack :)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string t : tokens) {
            if (t == "+") {
                int a2 = st.top();
                st.pop();
                int a1 = st.top();
                st.pop();
                st.push(a1 + a2);
            }
            else if (t == "-") {
                int a2 = st.top();
                st.pop();
                int a1 = st.top();
                st.pop();
                st.push(a1 - a2);
            }
            else if (t == "*") {
                int a2 = st.top();
                st.pop();
                int a1 = st.top();
                st.pop();
                st.push(a1 * a2);
            }
            else if (t == "/") {
                int a2 = st.top();
                st.pop();
                int a1 = st.top();
                st.pop();
                st.push(a1 / a2);
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};

/*
Runtime: 16 ms, faster than 25.55% of C++ online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 11.9 MB, less than 89.58% of C++ online submissions for Evaluate Reverse Polish Notation.
*/
