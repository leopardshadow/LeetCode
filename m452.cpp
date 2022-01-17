
// 2022.1.13 TM w/ G ><

/*
greedy
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2){
            return p1[1] < p2[1];
        });   
        int ans = 0, arrow = 0;
        for(auto pt : points) {
            if(ans == 0 || pt[0] > arrow) {
                ans++;
                arrow = pt[1];
            }
        }
        return ans;
    }
};

/*
Runtime: 460 ms, faster than 45.38% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
Memory Usage: 102.4 MB, less than 5.28% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
*/
