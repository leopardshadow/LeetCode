
// Weekly Contest 290

/*
幾何題
我搜索的範圍是圓心周圍的正方形
*/

class Solution {
    int square(int x) {
        return x * x;
    }
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        
        unordered_set<int> s;
        
        for (auto &cs : circles) {
            int x = cs[0],
                y = cs[1],
                r = cs[2];
            
            for (int i = x - r; i <= x + r; i++) {
                for (int j = y - r; j <= y + r; j++) {
                    if (square(i - x) + square(j - y) <= square(r)) {
                        s.insert(10000 * i + j);  // 1 <= x, y <= 100
                    }
                }
            }
        }
        
        return s.size();
    }
};
// set 比較慢一點
/*
Runtime: 1152 ms, faster than 45.45% of C++ online submissions for Count Lattice Points Inside a Circle.
Memory Usage: 25.1 MB, less than 18.18% of C++ online submissions for Count Lattice Points Inside a Circle.
*/

// 用 unordered_set 才快啊
/*
Runtime: 356 ms, faster than 100.00% of C++ online submissions for Count Lattice Points Inside a Circle.
Memory Usage: 22.8 MB, less than 18.18% of C++ online submissions for Count Lattice Points Inside a Circle.
*/
