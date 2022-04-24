
// Weekly Contest 290

/*
因為題目 input 的範圍差很多 (x: [1, 1E9], y: [1, 100])
所以選擇用 y 對應到 int 陣列，代表的是 x 的值，排序過後可以直接 binary search 找到大小
---
binary search: search insert place
https://www.tutorialspoint.com/search-insert-position-in-cplusplus
*/

class Solution {
    int binSearch(vector<int>& arr, int t) {
        if (arr.size() < 1)
            return 0;
        int l = 0, r = arr.size() - 1, pos;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] == t)
                return m;
            else if (arr[m] > t) {
                r = m - 1;
                pos = m;
            }
            else {
                l = m + 1;
                pos = m + 1;
            }
        }
        return pos;
    }
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        
        vector<int> ans(points.size(), 0);
        vector<int> y2xs[101];
        
        for (auto rs : rectangles) {
            y2xs[rs[1]].push_back(rs[0]);
        }
        for (int i = 0; i <= 100; i++)
            sort(y2xs[i].begin(), y2xs[i].end(), less<int>());
                
        for (int p = 0; p < points.size(); p++) {
            
            for (int i = points[p][1]; i <= 100; i++) {
                
                // cout << "i= " << i << " " << binSearch(y2xs[i], points[p][0]) << endl;
                ans[p] += (y2xs[i].size() - binSearch(y2xs[i], points[p][0]));
                

                // int j = 0;
                // while (j < y2xs[i].size() && y2xs[i][j] >= points[p][0]) {
                //     // cout << y2xs[i][j] << " " << i << endl;
                //     ans[p]++;
                //     j++;
                // }
                
            }
            
        }
        return ans;
    }
};
/*
Runtime: 934 ms, faster than 20.00% of C++ online submissions for Count Number of Rectangles Containing Each Point.
Memory Usage: 88.9 MB, less than 60.00% of C++ online submissions for Count Number of Rectangles Containing Each Point.
*/
