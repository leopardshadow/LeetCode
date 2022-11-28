
// 2022.11.28

/*
用 map 紀錄輸的次數
輸 0 次也要紀錄
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> loseTime;
        for (auto match : matches) {
            int win = match[0], lose = match[1];
            if (loseTime.find(win) == loseTime.end())
                loseTime[win] = 0;
            loseTime[lose]++;
        }
        vector<vector<int>> ans(2);
        for (const auto &[k, v] : loseTime) {
            if (v == 0)
                ans[0].push_back(k);
            else if (v == 1)
                ans[1].push_back(k);
        }
        return ans;
    }
};
/*
Runtime: 842 ms, faster than 85.44% of C++ online submissions for Find Players With Zero or One Losses.
Memory Usage: 179 MB, less than 51.66% of C++ online submissions for Find Players With Zero or One Losses.
*/
