//  DP D14

/*
跟我之前做有一題 hard，算正方形的作法好像
一開始居然被 sumRegion 的 return 的三元運算子搞到，不知道他的優先序就全加 () 吧
*/

class NumMatrix {
    vector<vector<int>> record;
public:
    NumMatrix(vector<vector<int>>& matrix): record(matrix) {
        // for(int r = 0; r < matrix.size(); r++) {
        //     record.push_back({});
        //     for(int c = 0; c < matrix[0].size(); c++) {
        //         record[r].push_back(0);
        //     }
        // }
        record[0][0] = matrix[0][0];
        for(int r = 1; r < matrix.size(); r++)
            record[r][0] = matrix[r][0] + record[r-1][0];
        for(int c = 1; c < matrix[0].size(); c++)
            record[0][c] = matrix[0][c] + record[0][c-1];
        for(int r = 1; r < matrix.size(); r++) {
            for(int c = 1; c < matrix[0].size(); c++) {
                record[r][c] = record[r-1][c] + record[r][c-1] - record[r-1][c-1] + matrix[r][c];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return   record[r2][c2] 
               - (c1 == 0 ? 0 : record[r2][c1-1]) 
               - (r1 == 0 ? 0 : record[r1-1][c2] )
               + (r1 == 0 || c1 == 0 ? 0 : record[r1-1][c1-1]);
    }
};

/*
Runtime: 368 ms, faster than 90.17% of C++ online submissions for Range Sum Query 2D - Immutable.
Memory Usage: 148 MB, less than 47.28% of C++ online submissions for Range Sum Query 2D - Immutable.
*/
