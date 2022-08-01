/*
其實也不用造出 table 啊，像這種題目在高中都是排列組合的題目
但是要注意 range 的問題，除法那邊可以除的就要趕快除，所以我在 for 迴圈內又包了一個 while
另外 ans 原本寫 int 也是會 Runtime error，乘起來爆掉了
 
  8!       7 8
------- = ----- = 28
 2! 6!      2!
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // compute (m + n -2)! / (m - 1)! / (n - 1)!
        unsigned long long ans = 1;
        
        // let m >= n
        if(m < n) swap(m, n);
        m -= 1;
        n -= 1;
        
        int j = 2;
        for(int i = m+1; i <= m + n; i++) {
            ans *= i;
            while(j <= n && ans % j == 0) {
                ans /= j;
                j += 1;
            }    
        }
        
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
Memory Usage: 6 MB, less than 70.03% of C++ online submissions for Unique Paths.
*/


//*******************************************************************************//


int uniquePaths(int m, int n){
    int mm = m < n ? m : n; // min m n
    int nn = m >= n ? m : n; // max m n
    int **table = malloc(sizeof(int*) * mm);
    for(int i = 0; i < mm; i++)
        table[i] = malloc(sizeof(int) * nn);
    
    for(int i = 0; i < mm; i++)
        table[i][0] = 1;
    
    for(int c = 1; c < nn; c++) {
        table[0][c%2] = 1;
        for(int r = 1; r < mm; r++) {
            table[r][c%2] = table[r][(c-1)%2] + table[r-1][c%2];
        }
    }
    return table[mm-1][(nn-1)%2];
}

/*
Runtime: 2 ms, faster than 25.99% of C online submissions for Unique Paths.
Memory Usage: 5.8 MB, less than 17.18% of C online submissions for Unique Paths.
*/


// 2022.8.1
