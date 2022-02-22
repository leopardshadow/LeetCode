
// 2022.2.22

/*
一開始吃了一個 Runtime Error，沒有注意到 int 的範圍..
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        long m = 1;
        for(int i = columnTitle.size() - 1; i >= 0; i--) {
            ans += (columnTitle[i] - 'A' + 1) * m;
            m *= 26;
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Number.
Memory Usage: 5.8 MB, less than 92.06% of C++ online submissions for Excel Sheet Column Number.
*/
