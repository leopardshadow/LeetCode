
// 2022.10.11 First Day after 10.10

/*
這題的感覺和 300 LIS 有一點點像，但是是比較簡單的版本
不過 LIS 沒有複習也忘惹
---
greedy 好吃靈感 QQ
---
參考了別人的做法
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (const int &x : nums) {
            if (x <= c1)
                c1 = x;
            else if (x <= c2)  // c2 >= x > c1
                c2 = x;
            else  // x > c1 && x > c2
                return true;
        }
        return false;
    }
};
/*
Runtime: 137 ms, faster than 43.71% of C++ online submissions for Increasing Triplet Subsequence.
Memory Usage: 61.5 MB, less than 67.34% of C++ online submissions for Increasing Triplet Subsequence.
*/
