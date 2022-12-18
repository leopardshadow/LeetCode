
/*
如果 a a+n，前面那個 a 就會被拿掉
所以留在 stack 的元素一定是漸漸變小的，
當下一天溫度進來，就把他放進 stack 裡比較，看他能幹掉幾個之前的溫度
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size(), 0);
        stack <int> st;  // store the **index**
        st.push(0);
        for(int i = 1; i < temps.size(); i++) {
            while(!st.empty() && temps[i] > temps[st.top()]) {
                ans[ st.top() ] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            ans[ st.top() ] = 0;
            st.pop();
        }
        return ans;
    }
};

/*
Runtime: 156 ms, faster than 60.71% of C++ online submissions for Daily Temperatures.
Memory Usage: 89 MB, less than 26.21% of C++ online submissions for Daily Temperatures.
*/


/*
11.13 daily
之前的寫法比較好，只要存 index 就好了，溫度數值再從 temps 讀
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size(), 0);
        stack<pair<int, int>> st;
        st.push(make_pair(0, temps[0]));
        for(int i = 1; i < temps.size(); i++) {
            while(!st.empty() && temps[i] > st.top().second) {
                // ans.push_back(i - st.top().first);
                ans[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push(make_pair(i, temps[i]));
        }
        // while(!st.empty()) {
        //     ans.push_back(0);
        //     st.pop();
        // }
        return ans;
    }
};

/*
Runtime: 152 ms, faster than 61.80% of C++ online submissions for Daily Temperatures.
Memory Usage: 92.9 MB, less than 10.10% of C++ online submissions for Daily Temperatures.
*/

// 2022.12.18
