// 2021.12.16

/*
---
這題之前就有嘗試寫了，但是 TLE，還沒解，結果今天每日題又遇到
---
我之前的想法是建立出 all source-destination 的 pair
接著對每個 node，找到從他出發最遠的距離，這就是他的 height
分別以每個 node 當出發點都會對應到一個 height，而答案就是那些對應到最小 height 的 nodes
這樣的作法答案會是對的，但冗余的計算有點多，time complexity 有點多
---
這題的 tag 是 topological sort，好酷

參考討論區 (https://leetcode.com/problems/minimum-height-trees/discuss/827284/c%2B%2B99-TC-with-explanation-using-bfs-top-sort-%3A) 後才寫出來

> "Basic idea: the roots of MHT must be the mid points of the longest leaf to leaf path in the tree.
> And to find the longest path, we can first find the farthest leaf from any node, and then find
> the farthest leaf from the node found above. Then these two nodes we found are the end points
> of the longest path. And last, we find the centers of the longest path."


我在做的時候會想怎麼抓出這棵 tree 的 root，但這裡的想法剛好相反，要怎麼從 leaf 出發，拔掉他們，把 root 留住

大致的概念是每次都把 leaf (deg = 1 的那些 nodes) 「拔掉」，並更新 deg 值，如果發現有製造出新的 leaf，就放進 queue 下一輪處理
如果都沒造出新的 leaf，那就代表現在還留著的都是 minimum height trees 的 root
*/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1)
            return {0};
        
        vector<int> deg(n, 0);
        vector<bool> ok(n, false);
        
        vector<vector<int>> graph(n);
        
        for(auto edge : edges) {
            // degree
            deg[edge[0]]++;
            deg[edge[1]]++;
            // adjancency list
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        
        vector<int> ans;
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1)
                q.push(i);
        }
        
        while(!q.empty()) {
            ans.clear();
            int qSize = q.size();
            while(qSize) {
                int cur = q.front();
                q.pop();
                ans.push_back(cur);
                for(int adj : graph[cur]) {
                    deg[adj]--;
                    if(deg[adj] == 1)
                        q.push(adj);
                }
                qSize--;
            }
        }
        
        return ans;
    }
};

/*
Runtime: 167 ms, faster than 6.99% of C++ online submissions for Minimum Height Trees.
Memory Usage: 29.4 MB, less than 53.03% of C++ online submissions for Minimum Height Trees.
*/

//******************************************************************************//
// 應該是對的，但是會 TLE
// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
//         // construct the source -- destination matrix with min cost first
//         vector<vector<int>> minDis(n, vector<int>(n, INT_MAX));
//         vector<vector<int>> dis_1(n);
        
//         queue<int> q;
        
//         for(auto edge : edges) {
//             dis_1[edge[0]].push_back(edge[1]);
//             dis_1[edge[1]].push_back(edge[0]);
//         }
        
//         for(int i = 0; i < n; i++)
//             minDis[i][i] = 0;
        
//         int step, qSize;
//         for(int src = 0; src < n; src++) {
            
//             step = 1;
            
//             for(int dst : dis_1[src])
//                 q.push(dst);
            
//             while(!q.empty()) {
                
//                 qSize = q.size();
                
//                 while(qSize) {
                
//                     int dst = q.front();
//                     q.pop();
//                     qSize--;                    

//                     minDis[src][dst] = step;

//                     for(int next : dis_1[dst]) {
//                         if(minDis[src][next] == INT_MAX)
//                             q.push(next);
//                     }
//                 }
//                 step++;
//             }
//         }

//         // use the source -- destination matrix to find out the results
//         int minHeight = INT_MAX;
//         vector<int> ans;
//         for(int from = 0; from < n; from++) {
//             int maxDis = -1;
//             for(int to = 0; to < n; to++) {
//                 if(from == to)
//                     continue;
//                 maxDis = max(maxDis, minDis[from][to]);
//             }
//             if(maxDis < minHeight) {
//                 ans.clear();
//                 ans.push_back(from);
//                 minHeight = maxDis;
//             }
//             else if(maxDis == minHeight) {
//                 ans.push_back(from);
//             }
//         }
//         return ans;
//     }
// };
