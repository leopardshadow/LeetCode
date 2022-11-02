
// 2022.11.2

/*
BFS!!
---
一開始 step++ 放錯地方，差一個大括號的範圍，像這種錯好難找QQ
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank_) {
        unordered_set<string> bank;
        for (const string &s : bank_)
            bank.insert(s);
        unordered_set<string> visited;
                        
        int step = 0;
        queue<string> q;
        q.push(start);
        visited.insert(start);
            
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                string x = q.front();
                q.pop();
                
                if (x == end)
                    return step;

                
                // generates mutations
                for (int j = 0; j < x.length(); j++) {
                    for (const char c : {'A', 'T', 'C', 'G'}) {
                        string m = x;
                        m[j] = c;
                        if (bank.count(m) && !visited.count(m)) {
                                                        
                            visited.insert(m);
                            q.push(m);
                        }
                    }
                }
            }
            step++;
        }
            
        return -1;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Genetic Mutation.
Memory Usage: 6.6 MB, less than 42.79% of C++ online submissions for Minimum Genetic Mutation.
*/
