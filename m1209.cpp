
// 2022.5.6

/*
這種題目用 stack 做很有效率，一個一個加上去，處理最新加進去的就好
印象中 Kickstart 也遇到過類似的題目，只是他不只要移除，移除後還要 push 東西進去（更新值）
---
偷看了 Hint
---
處理空的 stack 我原本是把判斷條件塞在迴圈裡 if (!st.empty() && c == st.top().first
)
看了討論區，用 dummy 的 value （{'#', 0}）來處理好像比較好看
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        // the stack 
        stack<pair<char, int>> st;
        st.push({'#', 0});
        
        for (const char &c : s) {
            
            // update the stack
            if (c == st.top().first)
                st.top().second += 1;
            else
                st.push({c, 1});
            
            // remove
            if (st.top().second == k)
                st.pop();
        }
                
        // answer string
        string ans = "";
        while (!st.empty()) {
            for (int i = 0; i < st.top().second; i++)
                ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
/*
Runtime: 40 ms, faster than 39.37% of C++ online submissions for Remove All Adjacent Duplicates in String II.
Memory Usage: 9.9 MB, less than 85.45% of C++ online submissions for Remove All Adjacent Duplicates in String II.
*/
