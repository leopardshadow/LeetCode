
// 2022.11.9

/*
怕 monotone stack ...
---
覺得題目有點難懂
["StockSpanner","next","next","next","next","next","next","next"]
[[],[100],[60],[60],[70],[80],[75],[85]]

75 那項我會覺得答案是 3，因為 60, 60, 70 都小於等於 75
但他的意思是從 today 開始算
*/

class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while (!st.empty() && st.top().first <= price) {
            ans += st.top().second;
            st.pop();
        }
        st.push({price, ans});
        return ans;
    }
};
/*
Runtime: 548 ms, faster than 20.59% of C++ online submissions for Online Stock Span.
Memory Usage: 84.3 MB, less than 22.76% of C++ online submissions for Online Stock Span.
*/
