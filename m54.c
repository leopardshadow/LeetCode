class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        
        vector<int> ans;

        /*
            -------> (a) |
            ^      |
     -- (d) |      | (b) --
            |      v
            <------- (c) |
        */
        int a = 0,
            b = m[0].size() - 1, // number of cols
            c = m.size() - 1,    // number of rows
            d = 0,
            i;
        // Example 2: (a, b, c, d) = (0, 3, 2, 0)
        //                           (1, 2, 1, 1)
        while(a <= c && d <= b) {
            // a
            for(i = d; i <= b; i++)
                ans.push_back(m[a][i]);
            a++;    // (1, 3, 2, 0)  (2, 3, 2, 0)
            if(a > c) break;
            // b
            for(i = a; i<= c; i++)
                ans.push_back(m[i][b]);
            b--;    // (1, 2, 2, 0)  (2, 2, 2, 0)
            if(d > b) break;
            // c
            for(i = b; i >= d; i--)
                ans.push_back(m[c][i]);
            c--;    // (1, 2, 1, 0)  (2, 2, 1, 0)

            // d
            for(i = c; i >= a; i--)
                ans.push_back(m[i][d]);
            d++;   // (1, 2, 1, 1)  (2, 2, 1, 1)
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 6.9 MB, less than 73.12% of C++ online submissions for Spiral Matrix.
*/