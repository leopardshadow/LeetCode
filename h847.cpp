
// 2022.2.26

/*
一開始我以為答案最大只會是 12，但這是錯誤的，如果所有點都只和 0 相連，走法會是  1 -> 0 -> 2 -> 0 -> 3 -> 0 ...，會超過 12
---
這題的 problem size 其實很小，node 數量最多只有 12，所以可以暴力解
需要考慮的狀態有：
1. 目前在哪個 node
2. 目前的 cost
3. 目前已經走過的點
只要把這些東西全部列出來和了解這三項東西前一個、後一個的關係就結束惹
---
自定義 class 要用 unordered_set 好麻煩RRR
結果最後發現想錯用不到 = =
跑過的點只要存 1, 3 就好，不用存 cost，所以用 pair 就好
*/

class State {
public:
    int curr, cost, visited;
    State(int curr, int cost, int visited) {
        this->curr = curr;
        this->cost = cost;
        this->visited = visited;
    }
};


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();  // number of nodes in the graph
        int target = (1 << n) - 1;
        
        queue<State> q;
        set<pair<int, int>> done;
        
        // start from each node
        for(int i = 0; i < n; i++) {
            State newState(i, 0, 1<<i);
            q.push(newState);
            done.insert({i, 1 << i});
        }
        
        while(!q.empty()) {
            
            State st = q.front();
            q.pop();
            
            if(st.visited == target)
                return st.cost;
                        
            // for every adjacent node
            for(int adj : graph[st.curr]) {
                int newVisted = st.visited | (1<<adj);
                if(done.count({adj, newVisted}))
                    continue;
                else {
                    q.push(State(adj, st.cost + 1, newVisted));  // next state
                    done.insert({adj, newVisted});
                }
            }
        }
        
        return -1;  // the graph is not connected
    }
};

/*
Runtime: 159 ms, faster than 34.16% of C++ online submissions for Shortest Path Visiting All Nodes.
Memory Usage: 18 MB, less than 48.35% of C++ online submissions for Shortest Path Visiting All Nodes.
*/
