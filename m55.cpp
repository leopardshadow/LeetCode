/*
Example 1
[2,3,1,1,4]
[f,f,f,f,f]
[t,f,f,f,f]   // starting from the first index
[t,t,t,f,f]   // i = 0, j = 1 .. 2
[t,t,t,t,f]   // i = 2, j = 1 .. 3
...
-------------
Example 2
[3,2,1,0,4]
[t,f,f,f,f]  // starting from the first index
[t,t,t,t,f]  // i = 0, j = 1 .. 3
[t,t,t,t,f]  // i = 1, j = 1 .. 2
[t,t,t,t,f]  // i = 2, j = 1 .. 1
[t,t,t,t,f]  // i = 3, j = 1 .. 0
[t,t,t,t,f]  // i = 4  (vec[4] = false -> break)
*/

// TLE ...
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
        
//         vector<bool> vec(nums.size(), false);
        
//         // starting from the first index
//         if(nums[0])
//             vec[0] = true;  // !!!!! corner case: [0,2,3] - false
        
//         for(int i = 0; i < nums.size(); i++) {
//             if(!vec[i]) continue;
            
//             for(int j = 1; j <= nums[i]; j++) {
//                 if(i + j < nums.size())
//                     vec[i + j] = true;
//             }
//         }
        
//         vec[0] = true;  // !!!!! corner case: [0] - true
        
//         return *vec.rbegin();
//     }
// };


/*
Hint. record the max index can reach
*/
/*
[2,3,1,1,4]
        0+2  1+3  2+1  3+1  4+5
mx: 0 -> 2 -> 4 -> 4 -> 4 -> 9
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i = 0; i < nums.size() && i <= mx; i++) {
            mx = max(mx, i + nums[i]);
        }
        return mx >= nums.size() - 1;
    }
};
/*
Runtime: 64 ms, faster than 60.22% of C++ online submissions for Jump Game.
Memory Usage: 48.4 MB, less than 49.09% of C++ online submissions for Jump Game.
*/