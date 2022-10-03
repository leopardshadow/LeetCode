
// 2022.10.3 Onboard

/*
因為希望 minCost 最小，所以把連續出現的顏色中，最大的數字留在原地，拿走其他比較小
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int now = -1, ans = 0;
        int sum = 0, biggest = 0;
        colors.push_back('.');
        neededTime.push_back(0);
        for (int i = 0; i < neededTime.size(); i++) {
            if (now == colors[i]) {
                sum += neededTime[i];
                biggest = max(biggest, neededTime[i]);  // keep the biggest one
            }
            else {
                ans += (sum - biggest);
                sum = neededTime[i];
                biggest = neededTime[i];
                now = colors[i];
            }
        }
        return ans;
    }
};
/*
Runtime: 431 ms, faster than 14.16% of C++ online submissions for Minimum Time to Make Rope Colorful.
Memory Usage: 96.9 MB, less than 16.55% of C++ online submissions for Minimum Time to Make Rope Colorful.
*/
