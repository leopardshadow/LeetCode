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


/*
下面是討論區裡的解答，他的 direction 轉變的方式還滿有趣的
巧妙得避掉了每次更新界線時的檢查
direction 轉換那邊是 FSM
*/
/*
        int direction=1;
        while(left<=right && top<=bottom)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++) v.push_back(matrix[top][i]);
                direction=2;
                top++;
            }
            
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++) v.push_back(matrix[i][right]);
                direction=3;
                right--;
            }
            
            else if(direction==3)
            {
                for(int i=right;i>=left;i--) v.push_back(matrix[bottom][i]);
                direction=4;
                bottom--;
            }
            
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--) v.push_back(matrix[i][left]);
                direction=1;
                left++;
            }
        }
*/