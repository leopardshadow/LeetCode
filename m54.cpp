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

//***************************************************************************//
// Review: 2021.11.28 before G VO

/*
這次嘗試用了 direc = (direc + 1) % 4 的寫法
但缺點是要改變原陣列，不然在判斷走過沒那邊好麻煩 (雖然應該還是有辦法辣)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rSize = matrix.size(), cSize = matrix[0].size();
        int direc = 0; // right
        //          1  // down
        //          2  // left
        //          3. // up
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        int r = 0, c= 0 ;
        for(int i = 0; i < rSize * cSize; i++)  {
            
            ans.push_back(matrix[r][c]);
            matrix[r][c] = -10000;
            
            int nr = r + dr[direc],
                nc = c + dc[direc];
            
            // when some condition is fulfilled, change the direction
            if(nr >= rSize || nr < 0 ||
               nc >= cSize || nc < 0 ||
               matrix[nr][nc] == -10000) {
                direc = (direc + 1) % 4;
            } 
            r = r + dr[direc];
            c = c + dc[direc];
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 6.8 MB, less than 71.57% of C++ online submissions for Spiral Matrix.
*/
