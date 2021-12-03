
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

//***************************************************************************//
// DP D6

/*
          [2,3,-2,4]
maxProd -  2 6 -2
minProd -  2 3 -6
  ans.  -  2 6  6 6
  
         [-2, 0,-1]
maxProd - -2  0 -1
minProd - -2  0 -1
  ans.  - -2  0  0

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0],
            minProd = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0)
                swap(maxProd, minProd);
            maxProd = max(maxProd * nums[i], nums[i]);
            minProd = min(minProd * nums[i], nums[i]);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};

/*
Runtime: 3 ms, faster than 85.44% of C++ online submissions for Maximum Product Subarray.
Memory Usage: 11.6 MB, less than 90.01% of C++ online submissions for Maximum Product Subarray.
*/


//***************************************************************************//
// 2021.12.3 剛結束 BQ 的 me

// 2021.12.3

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int nmax = nums[0],
            nmin = nums[0],
            ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0)
                swap(nmax, nmin);
            nmax = max(nums[i], nums[i] * nmax);
            nmin = min(nums[i], nums[i] * nmin);
            ans = max(ans, nmax);
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 81.49% of C++ online submissions for Maximum Product Subarray.
Memory Usage: 11.7 MB, less than 52.62% of C++ online submissions for Maximum Product Subarray.
*/
