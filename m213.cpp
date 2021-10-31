class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        else if(nums.size() <= 3) {
            return max(nums[2], max(nums[0], nums[1]));
        }
        return max(rob(nums, 0, nums.size() - 2),
                   rob(nums, 1, nums.size() - 1));
    }
    int rob(vector<int>& nums, int start, int end) {
        int nmax = -1;
        vector<int> t(nums.size(), 0);
        t[start] = nums[start];
        t[start+1] = nums[start+1];
        nmax = max(t[start], t[start+1]);
        for(int i = start + 2; i <= end; i++) {
            t[i] = max(nums[i] + t[i-2], t[i-1]);
            t[i-1] = nmax;
            nmax = max(nmax, t[i]);
        }
        return nmax;
    }
};


/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
Memory Usage: 8 MB, less than 16.50% of C++ online submissions for House Robber II.
*/