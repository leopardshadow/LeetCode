
// Weekly Contest 298
// 2022.6.19

/*
這題也錯了兩次，多了 10 分鐘
---
這題給一個 binnary sequence 和一個數字 k，要找最長的 binary subsequence，他所代表的數值要 <= k
---
可以用 greedy 想，想讓這個 sequence 儘量長，一定要多取 0，取完 0 之後會需要取 1，就從小的開始拿
---
錯的地方在於允許 leading zeros，所以如果前面一堆 0，超過 int 的範圍，我的 right shift 會出錯，但在這題是允許這種情形的，所以要另外處理
e.g. 
seq. = (100 個 0) 1, k = 1; 答案是 101，雖然前面的很多 0 沒辦法在 int 表示，但他卻會在答案裡
seq. = 1 (100 個 0) 1, k = 1; 答案也是 101
重要的是前面的 0，他會貢獻到答案裡，太大的 1 就不用管他了
---
我的作法是把 seq. 分成兩個部分 seq. == x + y
subseq. 是 (x 裡面的 0) + (y)
把 (x, y) 的組合跑過一次，就可以得到所有 subseq.，算出最大長度是多少
*/

typedef unsigned long long ULL;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        vector<int> acc0(s.length(), 0);
        int cnt0 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                cnt0++;
            acc0[i] = cnt0;
        }
        ULL n = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.length() - 1 - i >= 64) {  // many 0s in the front (since k <= 10^9)
                return acc0[i] + (s.length() - 1 - i + 1) - 1;  
            }
            n = n | (ULL)(s[i] - '0') << (s.length() - 1 - i);
            if (n > k) {
                return acc0[i] + (s.length() - 1 - i + 1) - 1;   
            }
        }
        return s.length();  // the whole string
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Binary Subsequence Less Than or Equal to K.
Memory Usage: 7.1 MB, less than 66.67% of C++ online submissions for Longest Binary Subsequence Less Than or Equal to K.
*/
