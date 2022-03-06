
// 2022.3.6
// Biweekly Contest 73

/*
這題因為要找的是 Ancestors，所以在整理題目給的 edges 時，倒過來存比較好
---
其實可以加速，例如 node 5 有 ancestor node 3，其實可以直接把 node 3 的 ancestor 們直接加給 3，不用再全部重跑一次
但是沒用也是過了，原本以為會 TLE 的
*/

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        map<int, vector<int>> bs_from_a;
        for(const auto &edge : edges)
            bs_from_a[edge[1]].push_back(edge[0]);
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            
            vector<bool> visited(n, false);
            queue<int> q;
            
            for(const int &b : bs_from_a[i]) {
                q.push(b);
                visited[b] = true;
            }
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                visited[node] = true;
                for(const int &b : bs_from_a[node])
                    if(!visited[b])
                        q.push(b);
            }
            
            vector<int> temp;
            for(int node = 0; node < n; node++)
                if(visited[node])
                    temp.push_back(node);
            ans.push_back(temp);
        }
        
        return ans;
    }
};

/*
Runtime: 256 ms, faster than 42.86% of C++ online submissions for All Ancestors of a Node in a Directed Acyclic Graph.
Memory Usage: 91 MB, less than 57.14% of C++ online submissions for All Ancestors of a Node in a Directed Acyclic Graph.
*/
