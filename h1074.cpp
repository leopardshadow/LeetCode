
// 2022.7.18

/*
我討厭 DP
---
參考了 lee215 的解
---
原本想搜尋所有可能值，這樣是 O(mmnn)
透過搜尋可以降成 O(mnn)

i / j 0 1 2 3 4 5
0     - - - - - - 
1     - - X X X -
2     - - X X X -
3     - - - - - -

the X rectangle is represented by i = 2 - 0, j = 3 - 1


*/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int m = A.size(), n = A[0].size(), ans = 0;
        
        // accumulate j
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] += A[i][j - 1];
        
        unordered_map<int, int> counter;
        // i, j -> decide the range of cols
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter = {{0,1}};
                int cur = 0;
                // k -> decide the range of rows -> search
                for (int k = 0; k < m; k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    ans += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        
        return ans;
    }
};
/*
Runtime: 1140 ms, faster than 54.25% of C++ online submissions for Number of Submatrices That Sum to Target.
Memory Usage: 94.6 MB, less than 87.97% of C++ online submissions for Number of Submatrices That Sum to Target.
*/
