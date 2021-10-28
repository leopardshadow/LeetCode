
/*
這題可以先從只有正數和零的情況想起
 2 3 0 1 4 0 3 2  2  0  1
 2 6 0 1 4 0 3 6 12  0  1
 2 6 6 6 6 6 6 6 12 12 12
 -------------------------
 接著再想有負數的情況
 nums: 2 3 -2...  4
 nmin: 2 6 2  2   4
 nmax: 2 2 6 -12 -12
 ans:  2 2 6      6
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int nmax = nums[0],
            nmin = nums[0],
             ans = nums[0];
        
        
        for(int i = 1; i < nums.size(); i++) {
            
            if(nums[i] < 0)
                swap(nmax, nmin);
            
            nmax = max(nums[i], nmax * nums[i]);
            nmin = min(nums[i], nmin * nums[i]);
            
            ans = max(ans, nmax);
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 81.04% of C++ online submissions for Maximum Product Subarray.
Memory Usage: 11.8 MB, less than 14.24% of C++ online submissions for Maximum Product Subarray.
*/