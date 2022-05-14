
// Biweekly Contest 78

/*
這週 Contest 只解出兩題 嗚嗚嗚。。。 
目前還沒過，晚點再寫
這題通過率 11.6% wwwww
*/

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        // sort by its begin
        sort(tiles.begin(), tiles.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        
        for (auto t : tiles)
            cout << t[0] << " " << t[1] << endl;
        
        int sum = 0;
        vector<int> acc(tiles.size() + 1);
        for (int i = 0; i < tiles.size(); i++) {
            acc[i] = sum;
            sum = sum + tiles[i][1] - tiles[i][0] + 1;
        }
        acc.back() = sum;

        
        vector<double> ends;
        for (int i = 0; i < tiles.size(); i++)
            ends.push_back(tiles[i][1]);
        
        int ans = 0;
        for (int i = 0; i < tiles.size(); i++) {
            int start = tiles[i][0];
            double carpenEnd = start + carpetLen - 1 + 0.5;
            
            auto it = upper_bound(ends.rbegin(), ends.rend(), carpenEnd, std::greater<int>());
            // if (start + carpetLen - 1 >= tiles.back()[1])
            //     it = ends.rbegin();
            if (it == ends.rend())
                it = ends.rbegin() - 1;
            int lastIdx = distance(it, ends.rend() - 1);
            
            int len = acc[lastIdx] - acc[i] + *it - tiles[lastIdx][0] + 1;
            
            // cout << lastIdx << endl;
            // cout << acc[lastIdx] - acc[i] << " " << *it - tiles[lastIdx][0] << endl;
            cout << len << endl;
            
            ans = max(ans, len);
        }
        cout << "---\n\n";
        return ans;
    }
};
