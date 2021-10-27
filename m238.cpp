/*
0 1 2 3 
123 023 013 012

X.  0.  01. 012  // step 1.
123 23. 3.  X    // step 2.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 1);
        
        // step 1.
        for(int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
            
        // step 2.
        int temp = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = ans[i] * temp;
            temp *= nums[i];
        }
            
        return ans;
    }
};

/*
Runtime: 20 ms, faster than 89.77% of C++ online submissions for Product of Array Except Self.
Memory Usage: 24 MB, less than 80.86% of C++ online submissions for Product of Array Except Self.
*/