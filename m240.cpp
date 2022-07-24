
// 2022.7.24

/*
O(m + n)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = matrix[0].size() - 1;
        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                c--;
            else
                r++;
        }
        return false;
    }
};
/*
Runtime: 258 ms, faster than 23.20% of C++ online submissions for Search a 2D Matrix II.
Memory Usage: 14.8 MB, less than 88.55% of C++ online submissions for Search a 2D Matrix II.
*/
