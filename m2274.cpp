
// Weekly Contest 293

/*
special 會把 bottom 到 top 的區間切成好幾塊
btm s1 s2 s3 ... sn top
把每一個區間長度算出來找最大的～
*/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        sort(special.begin(), special.end());
        ans = max(ans, special[0] - bottom);
        for (int i = 1; i < special.size(); i++)
            ans = max(ans, special[i] - special[i-1] - 1);
        ans = max(ans, top - special.back());
        return ans;
    }
};
/*
Runtime: 259 ms, faster than 25.00% of C++ online submissions for Maximum Consecutive Floors Without Special Floors.
Memory Usage: 58 MB, less than 100.00% of C++ online submissions for Maximum Consecutive Floors Without Special Floors.
*/
