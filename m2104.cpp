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

/*
Runtime: 171 ms, faster than 9.09% of C++ online submissions for Sum of Subarray Ranges.
Memory Usage: 10.5 MB, less than 18.18% of C++ online submissions for Sum of Subarray Ranges.
*/
