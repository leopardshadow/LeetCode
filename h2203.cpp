
// Weekly Contest 284
// 2022.3.13

/*
差一點點就可以清台 QQ
交叉比對之後，發現我在 Dijkstra 那邊算錯 嗚嗚嗚
---
想法是算 s1toX[i] + s2toX[i] + dst2X[i]，把 i = 0 .. n-1 全部跑一次就可以知道最小值
---
一開始在想 s1toX[i] + s2toX[i] 的後半段後不會出現路徑重疊的情況，答案是不會
因為如果有重疊，在 iterate i 到那個點時就會把舊答案蓋掉
---
e.g. src1 -> x -> y, src2 -> x -> y
在 i = y 時的確算出來的 subgraph 會比較大，因為 x -> y 這段被計算了兩次
但是在 iterate 到 i = x 時就會把舊的、比較長的 subgraph 覆蓋掉
---
概念是對的，但好可惜沒在 contest 寫出來
*/

class Solution {
    
    // dijkstra - to be revised
    void cal(vector<long long> &targ, vector<vector<pair<int, long long>>> &graph, int from) {
        targ[from] = 0;
        queue<int> q;
        q.push(from);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto e : graph[curr]) {
                int newCost = targ[curr] + e.second;
                if(newCost < targ[e.first]) {
                    targ[e.first] = newCost;
                    q.push(e.first);
                }   
            }
        }
    }
    
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        // graph
        vector<vector<pair<int, long long>>> graph(n);
        for(auto e : edges) {
            graph[e[0]].push_back({e[1], (long long)e[2]});
        }
        
        //
        vector<long long> s1toX(n, LLONG_MAX);
        cal(s1toX, graph, src1);
                
        //
        vector<long long> s2toX(n, LLONG_MAX);
        cal(s2toX, graph, src2);
        
        
        // reverse graph
        vector<vector<pair<int, long long>>> rgraph(n);
        for(auto e : edges) {
            rgraph[e[1]].push_back({e[0], (long long)e[2]});
        }

        //
        vector<long long> dst2X(n, LLONG_MAX);
        cal(dst2X, rgraph, dest);
        
        long long ans = LLONG_MAX;

        for(int i = 0; i < n; i++) {
            if(s1toX[i] != LLONG_MAX && s2toX[i] != LLONG_MAX && dst2X[i] != LLONG_MAX)
                ans = min(ans, s1toX[i] + s2toX[i] + dst2X[i]);
        }
        if(ans == LLONG_MAX)
            return -1;
        
        return ans;
    }
};
