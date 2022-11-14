
// 2022.11.14

/*
關鍵：有相同 row 或相同 col 的點可以合併成一個
因為刪的順序可以自己決定，所以不重要，重要的是最後剩下什麼
---
找 connected components 可以用 union find，但我這裡用 dfs
*/

class Solution {
    vector<bool> visited;
    int n;
    void dfs(int x, vector<vector<int>>& stones) {
        for (int i = 0; i < n; i++) {
            if (i != x && !visited[i] &&
                    (stones[i][0] == stones[x][0] ||
                     stones[i][1] == stones[x][1])
               ) {
                visited[i] = true;
                dfs(i, stones);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        visited.resize(n, false);
        int connected = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                connected++;
                dfs(i, stones);
            }
        }
        return n - connected;
    }
};
/*
Runtime: 759 ms, faster than 7.25% of C++ online submissions for Most Stones Removed with Same Row or Column.
Memory Usage: 14.1 MB, less than 88.33% of C++ online submissions for Most Stones Removed with Same Row or Column.
*/
