
// 2022.3.20

/*
我的作法是 brute-force，但其實不慢
輪流讓 top 和 bottom row 是 i = 1~ 6 (寫的時候兩個是反的)
---
還有很多做法

感覺越後面的題號有敘述越來越長的趨勢，contest 中遇到的題目都落落長，好考驗閱讀能力...
*/

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for(int i = 1; i <= 6; i++) {
            int cnt;
            // top
            cnt = 0;
            for(int j = 0; j < tops.size(); j++) {
                if(tops[j] == i)
                    ;
                else if(bottoms[j] == i)
                    cnt++;
                else {
                    cnt = INT_MAX;
                    break;
                }
            }
            ans = min(ans, cnt);
            // bottom
            cnt = 0;
            for(int j = 0; j < tops.size(); j++) {
                if(bottoms[j] == i)
                    ;
                else if(tops[j] == i)
                    cnt++;
                else {
                    cnt = INT_MAX;
                    break;
                }
            }
            ans = min(ans, cnt);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
Runtime: 178 ms, faster than 57.27% of C++ online submissions for Minimum Domino Rotations For Equal Row.
Memory Usage: 111.5 MB, less than 94.45% of C++ online submissions for Minimum Domino Rotations For Equal Row.
*/
