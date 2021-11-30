/*
Follow up:
only O(n) extra space
我是直接改在 triangle 上
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int l = 1; l < triangle.size(); l++) {
            triangle[l][0] += triangle[l-1][0];
            for(int i = 1; i < l; i++) {
                triangle[l][i] += min(triangle[l-1][i], triangle[l-1][i-1]);
            }
            triangle[l][l] += triangle[l-1][l-1];
        }
        int ans = INT_MAX;
        for(int n : triangle.back())
            ans = min(ans, n);
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 94.03% of C++ online submissions for Triangle.
Memory Usage: 8.7 MB, less than 57.35% of C++ online submissions for Triangle.
*/
