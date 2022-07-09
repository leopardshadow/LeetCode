
// 2022.7.9

/*
DP + max heap
---
原本找步數那邊會把 1 到 k 全部跑一次，現在改用 heap 來加速
---
用 heap 來找範圍內最大的，超過範圍的 pop 掉
*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        dp.back() = nums.back();
        priority_queue<pair<int, int>> pq;  // {nums[idx], idx}
        pq.push({nums.back(), nums.size() - 1});
        for (int i = nums.size() - 2; i >= 0; i--) {
            while (pq.size() && pq.top().second > i + k)  // pop those distance > k
                pq.pop();
            dp[i] = pq.top().first + nums[i];
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};
/*
Runtime: 345 ms, faster than 42.14% of C++ online submissions for Jump Game VI.
Memory Usage: 93.8 MB, less than 40.42% of C++ online submissions for Jump Game VI.
*/
