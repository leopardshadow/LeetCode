/*
雖然有一點點不明顯，但他其實是 binary search 的變形，我希望"找到"一個數字 x，使得 x * x == num
而數字本身就是排序的 XD
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned int l = 1, r = 1 << 16, m;
        while(l <= r) {
            m = (l + r) / 2;
            if(m * m == num)
                return true;
            else if(m * m < num)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }
};

/*
Runtime: 3 ms, faster than 17.29% of C++ online submissions for Valid Perfect Square.
Memory Usage: 5.9 MB, less than 16.83% of C++ online submissions for Valid Perfect Square.
*/
