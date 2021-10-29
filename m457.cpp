/*
2-pointer
*/
// (this doesn't work)
// class Solution {
// public:
    
//     bool sameSign(int a, int b) {
//         return !(a ^ b) >> 31;
//     }
    
//     bool circularArrayLoop(vector<int>& nums) {
//         int slow = 0, fast = 0;
//         int n = nums.size();
//         int sign;
        
//         while(fast < n && fast + nums[fast] < n) {
//             slow = (slow + nums[slow]) % n;
//             fast = (fast + nums[fast] + nums[ fast + nums[fast] ]) % n;
//             if(slow == fast) {
//                 // check the length & sign
//                 sign = nums[slow];
//                 do {
//                     slow = (slow + nums[slow]);
//                     if(!sameSign(sign, nums[slow]))
//                         return false;
//                 } while(slow != fast);
//                 return true;
//             }
//         }
//         return false;
//     }
// };

/*
Note.
(i + nums[i] + n) % n to wrap around negative number
*/

// Why [3,1,2] 's answer is true?????

class Solution {
public:
    
    // a, b not equals to 0
    bool sameSign(int a, int b) {
        if(a < 0) return b < 0;
        else return a > 0;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> visited(n, false);
        int i = 0, j;
        while(!visited[i]) {
            visited[i] = true;
            i = (i + nums[i] + n) % n;
        }
        j = (i + nums[i] + n) % n;
        int len = 1;
        while(j != i) {
            if(!sameSign(nums[j], nums[i])) return false;
            len++;
            j = (j + nums[j] + n) % n;
        }
        return len > 1;
    }
};


