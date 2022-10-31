
// 2022.10.31

/*
原本想以斜條為單位檢查
但 Hint 的對每個元素檢查左上比較直觀！
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++)
                if (matrix[i][j] != matrix[i-1][j-1])
                    return false;
        }
        return true;
    }
};
