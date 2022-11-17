
// 2022.11.17

/*
偏無聊的題目。。。
*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int r1 = (ax2 - ax1) * (ay2 - ay1);
        int r2 = (bx2 - bx1) * (by2 - by1);
        int overlap = 0;
        int xOverlap = min(ax2, bx2) - max(ax1, bx1);
        int yOverlap = min(ay2, by2) - max(ay1, by1);
        if (xOverlap > 0 && yOverlap > 0)
            overlap = xOverlap * yOverlap;
        return r1 + r2 - overlap;
    }
};
/*
Runtime: 28 ms, faster than 8.03% of C++ online submissions for Rectangle Area.
Memory Usage: 5.9 MB, less than 75.43% of C++ online submissions for Rectangle Area.
*/
