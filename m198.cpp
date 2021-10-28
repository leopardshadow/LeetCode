/*
 2  7   9  3  1
 2  7  11 11 12
 --------------
 2 1 1 2
 2 1 3 3
 2 2   4
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        
        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        
        vector <int> nmax(nums.size(), 0);
        int ans;
        
        nmax[0] = nums[0];
        nmax[1] = nums[1];
        
        ans = max(nmax[0], nmax[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            nmax[i] = max(nmax[i-1], nmax[i-2] + nums[i]);
            nmax[i - 1] = ans;  // ---------> key to [2, 1, 1, 2]
            ans = max(ans, nmax[i]);
        }
        return ans;
    }
};