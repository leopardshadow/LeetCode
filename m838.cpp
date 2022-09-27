
// 2022.9.27

/*
2-pointer
*/

class Solution {
    string ans;
    void fill(int x, int y, char c) {
        for (int i = x; i <= y; i++)
            ans[i] = c;
    }
public:
    string pushDominoes(string dominoes) {
        ans = "L" + dominoes + "R";
        int i = 1, j = 0;
        while (i < ans.size() && j < ans.size()) {
            while (i < ans.size() && ans[i] != '.')
                i++;
            j = i;
            while (j < ans.size() && ans[j] == '.')
                j++;
            j--;
                        
            if (i > ans.size() || j + 1 > ans.size())
                break;
            
            if (ans[i-1] == 'L' && ans[j+1] == 'L')
                fill(i, j, 'L');
            else if (ans[i-1] == 'R' && ans[j+1] == 'R')
                fill(i, j, 'R');
            else if (ans[i-1] == 'R' && ans[j+1] == 'L') {
                int m = (i + j) / 2;
                if ((j - i + 1) % 2 == 0) {
                    fill(i, m, 'R');
                    fill(m + 1, j, 'L');
                }
                else {
                    fill(i, m - 1, 'R');
                    fill(m + 1, j, 'L');
                }
            }
            else  // L ... R
                ;
            i = j + 1;
        }
        
        return ans.substr(1, dominoes.size());
    }
};
/*
Runtime: 44 ms, faster than 85.27% of C++ online submissions for Push Dominoes.
Memory Usage: 15.8 MB, less than 70.36% of C++ online submissions for Push Dominoes.
*/
