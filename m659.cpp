
// 2022.9.19


/*
先偷了 https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106493/C%2B%2B-O(n)-solution-two-pass
---
口試 累 onboard QQ
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, tails;
        // 1.
        for (int &i : nums)
            cnt[i]++;
        
        // 2.
        for (int &i : nums) {
            if (cnt[i] == 0)
                continue;
            cnt[i]--;
            if (tails[i-1] > 0){
                tails[i-1]--;
                tails[i]++;
            }
            else if (cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;
                cnt[i+2]--;
                tails[i+2]++;
            }
            else
                return false;
        }
        return true;
    }
};
