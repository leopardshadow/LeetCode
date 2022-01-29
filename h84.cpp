
// 2022.1.29

/*
以 heights[i] 作為高度，最左、最右最遠可以到哪裡
---
以題目的 [2,1,5,6,2,3] 來說
i h[i]   left  right
0  2      0     0
1  1      0     5 
2  5      2     3  
3  6      3     3
4  2      2     5   
5  3      5     5
---
好像還有 one-pass 的作法，但先這樣XD
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> left(n), right(n);
        stack<int> s; 
        
        // left
        for(int i = 0; i < n; i++) {
            // e.g. 4 3 2 1 0
            while(!s.empty() && heights[i] <= heights[s.top()]) 
                s.pop();
            // can go to left-most
            if(s.empty())
                left[i] = 0;
            else
                left[i] = s.top() + 1;
            s.push(i); 
        }
        
        while(!s.empty())
            s.pop() ; 
        // right    
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            // can go to right-most
            if(s.empty())
                right[i] = n - 1;
            else    
                right[i] = s.top() - 1;
            s.push(i); 
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};

/*
Runtime: 128 ms, faster than 70.36% of C++ online submissions for Largest Rectangle in Histogram.
Memory Usage: 66.3 MB, less than 36.96% of C++ online submissions for Largest Rectangle in Histogram.
*/
