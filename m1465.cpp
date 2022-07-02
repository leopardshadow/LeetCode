
// 2022.7.2

/*
對 cuts 排序
*/

class Solution {
    long maxX(int x, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int ret = max(cuts[0], x - cuts.back());
        for (int i = 1; i < cuts.size(); i++)
            ret = max(ret, cuts[i] - cuts[i-1]); 
        return (long)ret;
    }
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return maxX(h, horizontalCuts) * maxX(w, verticalCuts) % 1000000007;
    }
};
/*
Runtime: 76 ms, faster than 95.07% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
Memory Usage: 32.3 MB, less than 40.04% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
*/
