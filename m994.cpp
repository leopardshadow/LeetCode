struct Status {
public:
    int r, c, t;
    Status(int r, int c, int t) {
        this->r = r;
        this->c = c;
        this->t = t;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int time = 0;

        vector<Status>q1;
        
        int r, c;
        int rSize = grid.size();
        int cSize = grid[0].size();
        
        // traverse the grid and find all rotten oranges
        // and push into a queue
        for(r = 0; r < rSize; r++) {
            for(c = 0; c < cSize; c++) {
                if(grid[r][c] == 2) {
                    q1.push_back(Status(r, c, 0));
                }
            }
        }
                
        int t, dr, dc, nr, nc;
        // if the queue is not empty
        // pop each and mark its adjacent "fresh" orange to "rotten"
        while(!q1.empty()) {
            
            r = q1[0].r;
            c = q1[0].c;
            t = q1[0].t;
            q1.erase(q1.begin());
            time = max(time, t);

            for(dr = -1; dr <= 1; dr += 2) {
                nr = r + dr;
                nc = c;
                if(nr >= 0 &&
                   nr < rSize &&
                   nc >= 0 &&
                   nc < cSize &&
                   grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q1.push_back(Status(nr, nc, t+1));
                }
            }
        
            for(dc = -1; dc <= 1; dc += 2) {
                nr = r;
                nc = c + dc;
                if(nr >= 0 &&
                   nr < rSize &&
                   nc >= 0 &&
                   nc < cSize &&
                   grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q1.push_back(Status(nr, nc, t+1));
                }
            }
        }
        
        // still remains fresh
        for(r = 0; r < rSize; r++) {
            for(c = 0; c < cSize; c++) {
                if(grid[r][c] == 1) {
                    return -1;
                }
            }
        }
        
        return time;
    }
};

/*
Runtime: 8 ms, faster than 65.58% of C++ online submissions for Rotting Oranges.
Memory Usage: 13.1 MB, less than 79.67% of C++ online submissions for Rotting Oranges.
*/