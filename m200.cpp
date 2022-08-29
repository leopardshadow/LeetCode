class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0, x, y;
        vector<pair<int, int> > q;
        pair<int, int> p;
        
        for(int i = 0; i < grid.size(); i++) { // |
            for(int j = 0; j < grid[0].size(); j++) { // --
                if(grid[i][j] != '1') // we've counted that or it's sea
                    continue;
                else {  // it is part of island
                    ans += 1;
                    q.push_back(pair<int, int>(j, i));
                    grid[i][j] = '2';
                    while(!q.empty()) {
                        // add other connected part to the Q
                        p = q[0];
                        q.erase(q.begin());
                        
                        // be careful with the boundary
                        
                        // up
                        x = p.first;
                        y = p.second - 1;
                        if(y >= 0 && grid[y][x] == '1') {
                            q.push_back(pair<int, int>(x, y));
                            grid[y][x] = '2';
                        }
                        // down
                        x = p.first;
                        y = p.second + 1;
                        if(y < grid.size() && grid[y][x] == '1') {
                            q.push_back(pair<int, int>(x, y));
                            grid[y][x] = '2';
                        }
                        // left
                        x = p.first - 1;
                        y = p.second;
                        if(x >= 0 && grid[y][x] == '1') {
                            q.push_back(pair<int, int>(x, y));
                            grid[y][x] = '2';
                        }
                        // right
                        x = p.first + 1;
                        y = p.second;
                        if(x < grid[0].size() && grid[y][x] == '1') {
                            q.push_back(pair<int, int>(x, y));
                            grid[y][x] = '2';
                        }

                    }
                }
            }
        }
        return ans;
    }
};

/*
Runtime: 28 ms, faster than 89.36% of C++ online submissions for Number of Islands.
Memory Usage: 12.3 MB, less than 74.75% of C++ online submissions for Number of Islands.
*/

// 2022.8.29
