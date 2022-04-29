
// 2022.4.29

/*
graph coloring
因為 edge 的兩端不能屬於同一個 group (同一個 group 內大家不能有 edge)
---
union find 類的題目我喜歡 BFS > DFS
---
去 FE 一整天晚上再來寫好累XD
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> group(n, 0);
        
        // partition into group 1 & -1, there are no edges inside each group
        
        for (int i = 0; i < n; i++) {  // the graph may not be connected
            
            if (group[i])
                continue;
        
            queue<int> q;

            int color = 1;

            // start node
            group[i] = 1;
            q.push(i);

            while (!q.empty()) {

                int sz = q.size();
                int x = q.front();
                q.pop();
                for (int &adj : graph[x]) {
                    if (group[adj] == 0) {
                        group[adj] = -group[x];
                        q.push(adj);
                    }
                    else if (group[adj] == group[x])  // color neighbors with different color
                        return false;
                    else
                        ;
                }
            }
        }
        
        return true;
    }
};

/*
Runtime: 26 ms, faster than 76.14% of C++ online submissions for Is Graph Bipartite?.
Memory Usage: 13.7 MB, less than 41.19% of C++ online submissions for Is Graph Bipartite?.
*/
