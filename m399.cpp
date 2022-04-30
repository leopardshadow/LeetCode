
// 2022.4.30

/*
這題滿有趣的，大概知道他跟 graph 有關係，但是想不太到，最後看了討論區
如果 a / b = 2.0，那把 a -> b 的 edge 設成 2.0， b -> a 是 0.5，
同理， b / c = 3.0， b - > c 是 3.0， c - > b 則是 0.33333
a / c 是 a -> b -> c 的 path 所有 edge 代表的值相乘 a / c = (a / b) * (b / c)
---
一些小地方還可以改進，像是省掉重複的計算
---
如果我是面試官就會問：
 - 什麼時候會發生 contradiction、要怎麼偵測、遇到時要怎麼辦
*/

class Solution {
    
    map<string, vector<pair<string, double>>> adjList;
    
    double cal(string &a, string &b) {
        
        if (!adjList.count(a) || !adjList.count(b))
            return -1;
        
        map<string, double> weightFromA;
        queue<string> q;
        q.push(a);
        weightFromA[a] = 1.0;
        
        while (!q.empty()) {
            string x = q.front();
            q.pop();
            for (auto &adj : adjList[x]) {
                if (!weightFromA.count(adj.first)) {
                    q.push(adj.first);
                    weightFromA[adj.first] = weightFromA[x] * adj.second;
                }
            }
        }
        
        if (weightFromA.count(b))
            return weightFromA[b];
        else
            return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // adjacent list
        for (int i = 0; i < equations.size(); i++) {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        
        vector<double> ans;
        for (auto &q : queries)
            ans.push_back(cal(q[0], q[1]));
        
        return ans;
    }
};

/*
Runtime: 5 ms, faster than 30.48% of C++ online submissions for Evaluate Division.
Memory Usage: 8.5 MB, less than 30.89% of C++ online submissions for Evaluate Division.
*/
