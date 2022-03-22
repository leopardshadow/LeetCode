
// 2022.3.22

/*
看來這週是 greedy 週了
---
這題的 greedy rule 很簡單，因為想讓 lexicographical order 最小，所以會把最小的 char ('a') 先放前面，又因為總和要到 k，再把多的數從尾巴開始擺，擺到沒有為止
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        int i = n - 1;
        while(k) {
            int temp = min(25, k);
            k -= temp;
            ans[i] += temp;
            i--;
        }
        return ans;
    }
};
/*
Runtime: 27 ms, faster than 97.37% of C++ online submissions for Smallest String With A Given Numeric Value.
Memory Usage: 21.2 MB, less than 64.99% of C++ online submissions for Smallest String With A Given Numeric Value.
*/
