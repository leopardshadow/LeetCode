// Biweekly Contest 67

/*
是會連鎖的 @@ -
我原本以為是 union find，但 union find 好像只能是 undirected graph
---
這題其實可以看成在找 directed graph 的 max connected-componenets
這裡我採用了 BFS 的作法
*/

class Solution {
    long long square(long long a) {
        return a * a;
    }
    long long calDisSq(vector<int> p1, vector<int> p2) {
        return square(p1[0] - p2[0]) + square(p1[1] - p2[1]);
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int maxBomb = -1;
        
        int n = bombs.size();
        
        // detonates[i] will detonates the elements stored in the array
        vector<vector<int>> detonates(n);
        
        for(int i = 0; i < n; i++) {
            
            long long sqRadius = square(bombs[i][2]);
            
            for(int j = 0; j < n; j++) {
                
                if(calDisSq(bombs[i], bombs[j]) <= sqRadius) {
                    detonates[i].push_back(j);
                }                    
            }
        }
                   
        for(int i = 0; i < n; i++) {
            
            int curBomb = 0;
            vector<bool> bombed(n, false);            
            queue<int> q;
            bombed[i] = true;
            q.push(i);
            
            while(!q.empty()) {
                int b = q.front();
                q.pop();
                curBomb++;
                for(int nb : detonates[b]) {
                    if(!bombed[nb]) {
                        bombed[nb] = true;
                        q.push(nb);
                    }
                }
            }
            maxBomb = max(maxBomb, curBomb);
            if(maxBomb == n)
                break;
        }
        
        return maxBomb;
    }
};

/*
Runtime: 336 ms, faster than 30.77% of C++ online submissions for Detonate the Maximum Bombs.
Memory Usage: 72.5 MB, less than 7.69% of C++ online submissions for Detonate the Maximum Bombs.
*/
