#define PAC 2
#define ATL 1

class Solution {
public:
    
    int direc[5] = {0, 1, 0, -1, 0};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans;
        
        int rSize = heights.size();
        int cSize = heights[0].size();
        
        vector<int> emptyRow(cSize, 0);
        vector<vector<int> > table(rSize, emptyRow); 

        // Pacific ================================
        
        queue<pair<int, int>> q;
        pair<int, int> p;
        int nr, nc, r, c;
        
        for(r = 0; r < rSize; r++) {
            table[r][0] |= PAC;
            q.push({r, 0});
        }
        
        for(c = 1; c < cSize; c++) {
            table[0][c] |= PAC;
            q.push({0, c});
        }
        
        while(!q.empty()) {
            
            p = q.front();
            r = p.first;
            c = p.second;
            q.pop();
            
            for(int d = 0; d < 4; d++) {
                nr = r + direc[d];
                nc = c + direc[d+1];
                if(nr >= 0 && nr < rSize &&
                   nc >= 0 && nc < cSize &&
                   !(table[nr][nc] & PAC) &&
                   heights[nr][nc] >= heights[r][c])
                {
                    table[nr][nc] |= PAC;
                    q.push({nr, nc});
                }
            }
        }
        

        // Atlantic ================================
        
        for(r = 0; r < rSize; r++) {
            table[r][cSize-1] |= ATL;
            q.push({r, cSize-1});
        }
            
        for(c = 0; c < cSize - 1; c++) {
            table[rSize-1][c] |= ATL;
            q.push({rSize-1, c});

        }
        
        while(!q.empty()) {
            
            p = q.front();
            r = p.first;
            c = p.second;
            q.pop();
            
            for(int d = 0; d < 4; d++) {
                nr = r + direc[d];
                nc = c + direc[d+1];
                if(nr >= 0 && nr < rSize &&
                   nc >= 0 && nc < cSize &&
                   !(table[nr][nc] & ATL) &&
                   heights[nr][nc] >= heights[r][c])
                {
                    table[nr][nc] |= ATL;
                    q.push({nr, nc});
                }
            }
        }

        for(r = 0; r < rSize; r++) {
            for(int c = 0; c < cSize; c++) {
                if(table[r][c] == (PAC | ATL))  // the order of | ...
                    ans.push_back({r, c});
            }
        }
        return ans;
    }
};

/*
Runtime: 36 ms, faster than 92.28% of C++ online submissions for Pacific Atlantic Water Flow.
Memory Usage: 18.5 MB, less than 57.67% of C++ online submissions for Pacific Atlantic Water Flow.
*/


// 2022.8.31
