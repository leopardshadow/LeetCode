
// 2022.6.12

/*
雖然說是 erase，但是取的比較好想
---
sliding window~
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = nums[0], sum = nums[0], l = 0, r = 1;  // take [l, r)
        unordered_set<int> s;
        s.insert(nums[0]);
        while (r < nums.size()) {
            if (s.count(nums[r])) {
                sum -= nums[l];
                s.erase(nums[l]);
                l++;
            }
            else {
                sum += nums[r];
                s.insert(nums[r]);
                r++;
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
/*
Runtime: 757 ms, faster than 14.95% of C++ online submissions for Maximum Erasure Value.
Memory Usage: 127.3 MB, less than 14.58% of C++ online submissions for Maximum Erasure Value.
*/
