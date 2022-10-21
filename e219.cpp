
// 2022.10.21

/*
TGIF!
$MY_BIRTHDAY commits on the Github repo Leetcode/
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = i;
            }
            else {
                if (i - m[nums[i]] <= k)
                    return true;
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
/*
Runtime: 544 ms, faster than 9.04% of C++ online submissions for Contains Duplicate II.
Memory Usage: 80.4 MB, less than 15.96% of C++ online submissions for Contains Duplicate II.
*/
