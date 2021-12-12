// Weekly Contest 271

/*
居然 data type 是 long long，好少遇到喔
---
sliding window
*/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long nmax = nums[i], nmin = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                nmax = max(nmax, (long long)nums[j]);
                nmin = min(nmin, (long long)nums[j]);
                ans = ans + nmax - nmin;
            }
        }
        return ans;
    }
};
