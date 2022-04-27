
// 2022.4.27

/*
看來這週是 union find 週了，期待 segment tree 週..XD
想一下他動的感覺就可以知道他是 union find 的題目
但其實 union find 類型的題目不一定都要用 union find 解，BFS、DFS 也可以
知道各個 set 怎麼分之後可以在各組內排序，或是數出現的字母次數（因為就只有 a - z）
---
這裡我用的是 BPF 找 disjoint set + 抽出字串排序
---
這題如果改成只能換一次說不定還比較麻煩 (greedy?)
*/

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.length();
        
        // adjancency list
        vector<vector<int>> adjs(n);
        for (auto &p : pairs) {
            adjs[p[0]].push_back(p[1]);
            adjs[p[1]].push_back(p[0]);
        }
        
        // disjoint set
        vector<int> group(n, -1);
        for (int g = 0; g < n; g++) {
            
            if (group[g] != -1)
                continue;
            
            group[g] = g;
            queue<int> q;
            for (int &a : adjs[g]) {
                group[a] = g;
                q.push(a);
            }
            
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int &a : adjs[x]) {
                    if (group[a] == -1) {
                        group[a] = g;
                        q.push(a);
                    }                        
                }
            }
        }
        
        //
        map<int, vector<int>> groupElem;
        for (int i = 0; i < n; i++)
            groupElem[ group[i] ].push_back(i);
    
        for (auto ge : groupElem) {
            string sorted;
            for (auto e : ge.second)
                sorted.push_back(s[e]);
            sort(sorted.begin(), sorted.end());
            for (int i = 0; i < ge.second.size(); i++)
                s[ge.second[i]] = sorted[i];
        }
        
        return s;
    }
};
