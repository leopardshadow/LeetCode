
// Weekly Contest 284
// 2022.3.13

/*
我用有點 topological sort 的感覺
*/

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {

        int ans = 0;
        vector<vector<vector<int>>> grid2artif;
        for(int i = 0; i < n; i++) {
            grid2artif.push_back({});
            for(int j = 0; j < n; j++)
                grid2artif[i].push_back({});
        }
        
        
        vector<int> artiCnt(artifacts.size(), -1);
        
        for(int i = 0; i < artifacts.size(); i++) {
            int r1 = artifacts[i][0],
                c1 = artifacts[i][1],
                r2 = artifacts[i][2],
                c2 = artifacts[i][3];
            
            for(int r = r1; r <= r2; r++) {
                for(int c = c1; c <= c2; c++) {
                    grid2artif[r][c].push_back(i);
                }
            }
            
            artiCnt[i] = (r2 - r1 + 1) * (c2 - c1 + 1);
        }


        for(auto d : dig) {
            int r = d[0],
                c = d[1];
            
            for(int a : grid2artif[r][c])
                artiCnt[a]--;
        }
        
        for(int a : artiCnt) {
            if(a == 0)
                ans++;
        }

        return ans;
    }
};
/*
Runtime: 716 ms, faster than 30.44% of C++ online submissions for Count Artifacts That Can Be Extracted.
Memory Usage: 386.9 MB, less than 8.70% of C++ online submissions for Count Artifacts That Can Be Extracted.
*/
