
// 2022.5.14

/*
這題基本上就是在考 Dijkstra's algorithm
Dijkstra's 好不熟，偷看
--- 
應該用 adjacency list 的，matrix 寫起來還比較麻煩
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // construct the graph (adjacency matrix)
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, INT_MAX));
        for (const auto &t : times)
            mat[t[0]][t[1]] = t[2];
        
        // the shortest path from k to other nodes
        vector<int> delays(n + 1, INT_MAX);
        delays[k] = 0;
        delays[0] = 0;  // not used, index from 1 to n
        
        // pq
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // { curTime, curNode }
        pq.push({0, k});
        
        // dijkstra
        while (!pq.empty()) {
            int curT = pq.top().first;
            int curN = pq.top().second;
            pq.pop();
            
            if (curT > delays[curN])
                continue;
            
            // edges from curN to _
            for (int i = 1; i <= n; i++) {
                
                // no edges between curN & i
                if (mat[curN][i] == INT_MAX)
                    continue;
                
                // update shorter path
                if (curT + mat[curN][i] < delays[i]) {
                    delays[i] = curT + mat[curN][i];
                    pq.push({delays[i], i});
                }
            }
        }
                                
        int ans = *max_element(delays.begin(), delays.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
Runtime: 121 ms, faster than 88.70% of C++ online submissions for Network Delay Time.
Memory Usage: 37.4 MB, less than 93.33% of C++ online submissions for Network Delay Time.
*/
