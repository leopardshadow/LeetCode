/*
Besides bit operation, 
https://blog.techbridge.cc/2020/02/16/leetcode-%E5%88%B7%E9%A1%8C-pattern-cyclic-sort/
try cyclic-sort!!
*/

/*
[9,6,4,2,3,5,7,0,1]  size = 9
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // int n;
        // if(num.size() == 0) return 1;
        // else
        int n = nums.size() + 1;
        
        // 1 0 0 .. 0 -> m 0s
        int m = 0;
        while(n) {
            m++;
            n = n >> 1;
        }
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        for(int i = nums.size() + 1; i < (1<<m); i++) {
            ans ^= i;
        }
        return ans;   
    }
};

/*
Runtime: 8 ms, faster than 99.81% of C++ online submissions for Missing Number.
Memory Usage: 18.1 MB, less than 18.80% of C++ online submissions for Missing Number.
*/



// 2022.5.28

/*
之前是用 bit operation 的方式做，這次換一個也是 TC O(n) SC O(1) 的方法
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (const int &n : nums)
            sum += n;
        return (nums.size() + 1) * (nums.size()) / 2 - sum;
    }
};
/*
Runtime: 20 ms, faster than 80.22% of C++ online submissions for Missing Number.
Memory Usage: 17.9 MB, less than 65.37% of C++ online submissions for Missing Number.
*/
