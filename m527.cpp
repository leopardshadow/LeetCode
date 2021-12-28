
//******************************************************************************//
// 12.28 - 1 Day Before A VO

/*
這題其實就是在問圖中有幾個 connected components，讓我想到之前 LC contest secret 那題 hard
但因為這題比較簡單 (沒有在那裡變來變去，測資也比較小)，所以不一定要用 union find，單純用 dfs / bfs 也可以解
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<bool> proc(n, false);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(!proc[i]) {
                ans++;
                queue<int> q;
                q.push(i);
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(int adj = 0; adj < n; adj++) {
                        if(!proc[adj] && isConnected[node][adj]) {
                            q.push(adj);
                            proc[adj] = true;
                        }                            
                    }
                }                
            }
        }
        
        return ans;
    }
};

/*
Runtime: 24 ms, faster than 58.88% of C++ online submissions for Number of Provinces.
Memory Usage: 14.1 MB, less than 25.82% of C++ online submissions for Number of Provinces.
*/
