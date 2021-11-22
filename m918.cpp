// To-do: 試著用 slinding window 解，複製一份貼到 nums 尾巴，找最大的 subarray (長度限制在 n)



/*
這題是 53. Maximum Subarray 的變形，原來用來解那題的演算法還有自己的名字，叫 Kadane's algorithm
*/

// 果然這樣會 TLE ...
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums, int start) {
//         int ans = nums[start], curSum = nums[start];
//         for(int i = 1; i < nums.size(); i++) {
//             curSum = max(nums[(start + i) % nums.size()], curSum + nums[(start + i) % nums.size()]);
//             ans = max(ans, curSum);
//         }
//         return ans;
//     }

//     int maxSubarraySumCircular(vector<int>& nums) {
//         int ans = nums[0];
//         for(int i = 0; i < nums.size(); i++)
//             ans = max(ans, maxSubArray(nums, i));
//         return ans;
//     }
// };


/* 
          0. 1 2  3
         [3,-1,2,-1]
 start -  0  0 2  2 
curSum -  3  2 2  1 > 0
  ans  -  3  3 3  3
 
         [5,-3,5]
 start -  0  0 
curSum -  5  2
  ans  -  5  5

*/
// the logic is not correct ...
// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         vector<int> recordMax(nums.size(), -1); // recordMax[i] is the sum of maxsubarray [0, i]
//         recordMax[0] = nums[0];
//         int ans = nums[0], curSum = nums[0];
//         int subarrStart = 0;
//         for(int i = 1; i < nums.size(); i++) {
//             curSum = curSum + nums[i];
//             if(nums[i] >= curSum) {
//                 curSum = nums[i];
//                 subarrStart = i;
//             }
//             ans = max(ans, curSum);
//             recordMax[i] = ans; 
//         }
//         if(curSum > 0) {
//             for(int i = 0; i < subarrStart; i++) {
//                 ans = max(ans, curSum + recordMax[i]);
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = nums[0], nmax = nums[0];   
        int curMin = nums[0], nmin = nums[0];
        int total = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            curMax = max(nums[i], curMax + nums[i]);  // curMax & nmax is exactly what we have at 53. Maximum Subarray
            nmax = max(nmax, curMax);
            
            curMin = min(nums[i], curMin + nums[i]);
            nmin = min(nmin, curMin);
            
            total += nums[i];
        }
        int circularSum = total - nmin; // Key to this problem!!!
        if(circularSum == 0)  // to deal with all-negative array
            return nmax;
        return max(nmax, circularSum);
    }
};

/*
Runtime: 80 ms, faster than 25.87% of C++ online submissions for Maximum Sum Circular Subarray.
Memory Usage: 39.9 MB, less than 27.61% of C++ online submissions for Maximum Sum Circular Subarray.
*/
