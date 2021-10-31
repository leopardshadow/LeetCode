/*
  v             v
1 8 6 2 5 4 8 3 7
0 1 2 3 4 5 6 7 8
Hint: 2-pointer
*/

/*
用兩個指針來指，如果遇到左邊的高度比右邊小，那就移動左邊，這樣才有機會變好，反之則移動右邊
*/

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0, area;
        int l = 0, r = heights.size() - 1;
        while(l < r) {
            area = (r - l) * min(heights[l], heights[r]);
            ans = max(ans, area);
            if(heights[r] >= heights[l]) l++;
            else r--;
        }
        return ans;
    }
};


/*
Runtime: 72 ms, faster than 96.49% of C++ online submissions for Container With Most Water.
Memory Usage: 59.1 MB, less than 39.03% of C++ online submissions for Container With Most Water.
*/