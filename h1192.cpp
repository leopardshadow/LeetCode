
// 2022.5.18

/*
體感上 Leetcode 已經好久沒出 Hard 了，之前都是 Easy, Medium 在循環 XD
---
題目舉的例子都很簡單，看起來只要找最邊邊的邊緣 node 就好，但其實不是
0 -- X -- 1 -- 2
在這個例子中，每一條 edge 都是 critical connection，斷開任意一條都會讓 node 不在彼此連接
---
不知道 Tarjan's algorithm 的話這題真的寫不出來欸 ... QQ 
---
其實這個題目也可以換個方式出，給一些彼此可能互相不連接的 nodes，如何讓他整體連接在一起
作法也是先找到 strongly connected componenets，連接他們就好
*/

class Solution {
    
    vector<vector<int>> adjList, ans;
    int n, index;
    
    vector<int> disc, low;
    vector<bool> visited;
    
    //
    void tarjan() {
            
        //
        disc.resize(n, -1);
        low.resize(n, -1);
        visited.resize(n, false);
        
        //
        for (int i = 0; i < n; i++) {
            if (visited[i] == false)
                dfs(i, i);
        }
    }
    
    //
    void dfs(int node, int parent) {
        //
		disc[node] = low[node] = index++;
        visited[node] = true;
        
        for (const int &adj : adjList[node]) {
            if (parent == adj)
                continue;
            if (visited[adj] == false) {
                dfs(adj ,node);
                low[node] = min(low[node], low[adj]);
                if (disc[node] < low[adj])
                    ans.push_back({node ,adj});
            }
            else 
                low[node] = min(low[node], disc[adj]);
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        this->n = n;
        this->index = 0;
        
        // construct the graph: adjacency list
        adjList.resize(n);
        for (const auto &conn : connections) {
            adjList[conn[0]].push_back(conn[1]);
            adjList[conn[1]].push_back(conn[0]);
        }
        
        // Tarjan's algorithm
        tarjan();
                
        return ans;
    }
};
/*
Runtime: 626 ms, faster than 87.69% of C++ online submissions for Critical Connections in a Network.
Memory Usage: 179.8 MB, less than 55.13% of C++ online submissions for Critical Connections in a Network.
*/
