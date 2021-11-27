// Biweekly Contest 66


/*
覺得這題和算正方形的有異曲同工之妙，不過正方形的單純一點
*/


class Solution {
    int rSize, cSize;
public:
    
    int getCnt(vector<vector<int>>& grid, vector<vector<int>>& newgrid) {
        int cnt = 0;
        
        // normal
        for(int r = 1; r < rSize; r++) {
            for(int c = 1; c < cSize - 1; c++) {
                if((grid[r][c+1] & 1) && (grid[r][c] & 1) && (grid[r][c-1] & 1) && (grid[r-1][c] & 1)) {
                    newgrid[r][c] |= 1;
                    cnt++;
                }
                    
            }
        }
        
        // reverse
        for(int r = 0; r < rSize - 1; r++) {
            for(int c = 1; c < cSize - 1; c++) {
                if((grid[r][c+1] & 2) && (grid[r][c] & 2) && (grid[r][c-1] & 2) && (grid[r+1][c] & 2)) {
                    newgrid[r][c] |= 2;
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void clear(vector<vector<int>>& grid) {
        for(int r = 0; r < rSize; r++) {
            for(int c = 0; c < cSize; c++) {
                grid[r][c] = 0;
            }
        }
    }
    
    
    int countPyramids(vector<vector<int>>& grid) {
        
        int ans = 0;
        rSize = grid.size();
        cSize = grid[0].size();
        
        // vector<int> emptyRow(cSize, 0);
        // vector<vector<int>> table(rSize, emptyRow);
        
        vector<int> emptyRow(cSize, 0);
        vector<vector<int>> newGrid(rSize, emptyRow);

        
        for(int r = 0; r < rSize; r++) {
            for(int c = 0; c < cSize; c++) {
                if(grid[r][c])
                    grid[r][c] = 3;
            }
        }

        
        int cnt;
        while((cnt = getCnt(grid, newGrid)) != 0) {
            grid = newGrid;
            clear(newGrid);
            ans += cnt;
        }
            
        return ans;
    }
};
