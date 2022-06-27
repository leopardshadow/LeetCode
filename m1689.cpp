
// 2022.6.27

/*
讀懂題目意思後這根本是 easy 吧
*/

class Solution {
public:
    int minPartitions(string n) {
        char maxChar = -1;
        for (int i = 0; i < n.length(); i++)
            maxChar = max(maxChar, n[i]);
        return maxChar - '0';
    }
};
/*
Runtime: 39 ms, faster than 63.06% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
Memory Usage: 13.5 MB, less than 65.18% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
*/
