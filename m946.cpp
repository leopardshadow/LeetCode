
// 2022.3.16

/*
stack
還滿喜歡這種題目的 XD
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int popId = 0;
        for(const int &pushItem : pushed) {
            st.push(pushItem);
            while(st.size() > 0 && popId < popped.size() && st.top() == popped[popId]) {
                st.pop();
                popId++;
            }
        }
        return st.size() == 0 && popId == popped.size();
    }
};

/*
Runtime: 11 ms, faster than 67.80% of C++ online submissions for Validate Stack Sequences.
Memory Usage: 15.2 MB, less than 81.35% of C++ online submissions for Validate Stack Sequences.
*/
