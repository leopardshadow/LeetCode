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



// DP D4

// Key: 紀錄最大可以到達的 index，之後往前走，更新最大可以到達的 index

/*
2 3 1 1 4
s....
  s......
mI = 0
mI = 0 + 2 = 2
i = 1:
i = 2: 
  
3 2 1 0 4
s......
  s....
    s..
      s
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        //                   注意 i 的範圍       vvvvvvvvvvvvvvvvvvvv
        for(int i = maxIndex; i <= maxIndex && i <= nums.size() - 1; i++) {
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return maxIndex >= nums.size() - 1;
    }
};

/*
Runtime: 71 ms, faster than 37.99% of C++ online submissions for Jump Game.
Memory Usage: 48.1 MB, less than 94.79% of C++ online submissions for Jump Game.
*/




// 寫了 45. Jump Game II 之後來試試 greedy + BFS 的寫法
// 說明就去看那吧
 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0, r = 0, nextR = -1;
        while(r < nums.size() - 1) {
            for(int i = l; i <= r; i++)
                nextR = max(nextR, i + nums[i]);
            if(r == nextR)
                break;
            l = r + 1;
            r = nextR;
        }
        return r >= nums.size() - 1;
    }
};

/*
Runtime: 48 ms, faster than 95.92% of C++ online submissions for Jump Game.
Memory Usage: 48.4 MB, less than 47.98% of C++ online submissions for Jump Game.
*/
