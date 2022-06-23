
// 2022.6.23

/*
原本以為是 DP，沒想到是 heap
如果他給的是 [start, end] 可能就是 DP
---
偷看了討論區 ><
*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        // sort by its end day
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;  // will choose the one with smaller duration
        int sum = 0;
        for (auto c : courses) {
            sum += c[0];
            pq.push(c[0]);
            if (sum > c[1]) {  // if the total duration is too long,
                sum -= pq.top();  // remove the longest one
                pq.pop();
            }
        }
        return pq.size();
    }
};
/*
Runtime: 307 ms, faster than 69.67% of C++ online submissions for Course Schedule III.
Memory Usage: 63.5 MB, less than 21.80% of C++ online submissions for Course Schedule III.
*/
