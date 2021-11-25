/*
看完提示寫出來的，沒想到這麼慢 @@

If we do brute-froce:
every positions take turns to be the upper-left corner O(n^2)
and expands its size gradually O(n)
if it contains all 1 for that square !! for this steps, if we're just counting the 1s it will be O(n^2)

it will be O(n^5) in total, definitely will lead to a TLE

but in last step, we're doing redundant things, the process can be simplified
we can reduce the time to O(1)
so the overall time complxity will be O(n^3)

這是我的解法，看了討論區發現有超級精簡的解法! (不是用這個方法ㄉ)

we construct a table, table[r][c] represents the 1s between the square (0, 0) (upper-left corner) and (r, c) (bottom-right corner)

┌───────────────────┬───────────┐                                                                                          
│                   │           │                                                                                          
│                   │           │                                                                                          
│                   │           │                                                                                          
│            .──────┴──.        │                                                                                          
│           ╱           ╲       │                                   ┌───────────┐                                          
├──────────(      a      )──────┤                                   │           │                                          
│           `.         ,'       │                                   │     .─.   │                                          
│             `─────┬─'         │                                   │    ;   :  │                                          
│                   │           │                                   │    │   │  │                                          
│                   │           │                                   │    │ c │  │                                          
│                   │           │                                   ├────┤   ├──┤                                          
└───────────────────┴───────────┘                                   │    │   │  │                                          
                                                                    │    :   ;  │                                          
                                                                    │     ╲ ╱   │                                          
                     ┌───────┐                                      │      '    │                                          
                     │ (0,0) │                                      │           │                                          
                     └───────┼───────────────────┬───────────┐      └───────────┘                                          
                             │                   │           │                                                             
                             │                   │           │                                                             
┌────────────────────┐       │                   │           │                                                             
│                    │       │           ┌───────┤           │                                                             
│    .───────────.   │       │           │ (r,c) │           │                                                             
│   (      d      )  │       ├───────────┴───────┼───────────┼-                              
│    `───────────'   │       │                   │           │  \                                                      
│                    │       │                   │           │   \                                              
└────────────────────┘       │                   │           │       square size                                              
                             │                   │           │   /                                                      
                             │                   │           │  /                                                     
                             └───────────────────┴───────────┴-                             
                                                                                                                           
                                                                                                                           
                                                                                                                           
           ┌────────────────────┬───────────┐                                                                              
           │                    │           │                                                                              
           │             .──────┴────.      │                ┌───────────┐                                                 
           │            (      b      )     │                │           │                 ┌──────────────────────────────┐
           │             `──────┬────'      │                │           │                 │                              │
           │                    │           │                │      ─────┼───────────────▶ │        a - b - c + d         │
           └────────────────────┴───────────┘                │           │                 │                              │
                                                             │           │                 └──────────────────────────────┘
                                                             └───────────┘                                                 

*/


class Solution {
    vector<vector<int>> table;
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int rowSize = matrix.size(), colSize = matrix[0].size();
        // create and init the table
        table.resize(rowSize);
        for(int i = 0; i < rowSize; i++)
            table[i] = vector<int>(colSize, 0);
        
        table[0][0] = matrix[0][0];
        
        for(int r = 1; r < rowSize; r++)
            table[r][0] = table[r-1][0] + matrix[r][0];
            
        for(int c = 1; c < colSize; c++)
            table[0][c] = table[0][c-1] + matrix[0][c];
        
        for(int r = 1; r < rowSize; r++) {
            for(int c = 1; c < colSize; c++) {
                table[r][c] = table[r-1][c] + table[r][c-1] - table[r-1][c-1] + matrix[r][c];
            }
        }

        for(int r = 0; r < rowSize; r++) {
            for(int c = 0; c < colSize; c++) {
                
                if(matrix[r][c])
                    ans++;
                            
                for(int sqSize = 2; ; sqSize++) {
                    
                    int rightBottomR = r + sqSize - 1,
                        rightBottomC = c + sqSize - 1;
                    
                    if(rightBottomR >= rowSize || rightBottomC >= colSize)
                        break;
                    
                    int a1 = table[rightBottomR][rightBottomC];
                    int a2 = (c - 1 < 0 ? 0 : table[rightBottomR][c-1]);
                    int a3 = (r - 1 < 0 ? 0 : table[r-1][rightBottomC]);
                    int a4 = (r - 1 < 0 || c - 1 < 0 ? 0 : table[r-1][c-1]);
                    
                    int count1 = a1 - a2 - a3 + a4;
                    
                    if(count1 == sqSize * sqSize)
                        ans++;
                }
            }
        }
        return ans;
    }
};

/*
Runtime: 748 ms, faster than 5.02% of C++ online submissions for Count Square Submatrices with All Ones.
Memory Usage: 26.4 MB, less than 7.07% of C++ online submissions for Count Square Submatrices with All Ones.
*/
