/*
這題的 tag 是 topological sort

(TLE now ...)

*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // construct the source -- destination matrix with min cost first
        vector<vector<int>> minDis(n, vector<int>(n, INT_MAX));
        vector<vector<int>> dis_1(n);
        
        queue<int> q;
        
        for(auto edge : edges) {
            dis_1[edge[0]].push_back(edge[1]);
            dis_1[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i < n; i++)
            minDis[i][i] = 0;
        
        int step, qSize;
        for(int src = 0; src < n; src++) {
            
            step = 1;
            
            for(int dst : dis_1[src])
                q.push(dst);
            
            while(!q.empty()) {
                
                qSize = q.size();
                
                while(qSize) {
                
                    int dst = q.front();
                    q.pop();
                    qSize--;                    

                    minDis[src][dst] = step;

                    for(int next : dis_1[dst]) {
                        if(minDis[src][next] == INT_MAX)
                            q.push(next);
                    }
                }
                step++;
            }
        }

        // use the source -- destination matrix to find out the results
        int minHeight = INT_MAX;
        vector<int> ans;
        for(int from = 0; from < n; from++) {
            int maxDis = -1;
            for(int to = 0; to < n; to++) {
                if(from == to)
                    continue;
                maxDis = max(maxDis, minDis[from][to]);
            }
            if(maxDis < minHeight) {
                ans.clear();
                ans.push_back(from);
                minHeight = maxDis;
            }
            else if(maxDis == minHeight) {
                ans.push_back(from);
            }
        }
        return ans;
    }
};
