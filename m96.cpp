
/*
0 - 1
===
1 - 1
===
2 - 2
===
3 - 
 2 + 1 + 2 = 5
 i = 3
    j = 1 - [0] * [2]
    j = 2 - [1] * [1]
    j = 3 - [2] * [0]
===
4 - 14
(1) 2 3 4 - 1 * 5
1 (2) 3 4 - 1 * 2
1 2 (3) 4 - 2 * 1
1 2 3 (4) - 5 * 1
===

*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> table;
        table.push_back(1); // 0
        table.push_back(1); // 1
        table.push_back(2); // 2
        
        int i, tmp;
        for(i = 3; i <= n; i++) {
            tmp = 0;
            for(int j = 1; j <= i; j++)
                tmp += table[j - 1] * table[i - j];
            table.push_back(tmp);
        }
        return table[n];
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
Memory Usage: 6 MB, less than 37.05% of C++ online submissions for Unique Binary Search Trees.
*/