// binary search
// with transformation between 1D array and 2D array

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int rows = mat.size(), cols = mat[0].size();
        int left = 0, right = rows * cols - 1;
        int mid, mValue;
        
        while(left <= right) {
            mid = (left + right) / 2;
            mValue = mat[ mid / cols ][ mid % cols ];
            if(mValue == target)
                return true;
            else if(mValue > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.6 MB, less than 51.15% of C++ online submissions for Search a 2D Matrix.
*/
