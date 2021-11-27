/*
0 1 2 3 
123 023 013 012

X.  0.  01. 012  // step 1.
123 23. 3.  X    // step 2.

補充：
後來想想這題的關鍵應該在於把 123 023 013 012 這個寫出來後，發現中間兩個是 (0)23 和 (01)3，如果往前往後推，就會是
123 -- (0)23 -- (01)3 -- (012)，小括號包起來的部分逐漸增加，沒有小括號的部分漸漸減少
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

//***************************************************************************//
// 2021.11.27

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> table(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
            table[i] = nums[i-1] * table[i-1];
        ans.back() = table.back();
        int temp = 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            temp *= nums[i+1];
            ans[i] = temp * table[i];
        }
        return ans;
    }
};

/*
Runtime: 26 ms, faster than 43.41% of C++ online submissions for Product of Array Except Self.
Memory Usage: 24.5 MB, less than 47.40% of C++ online submissions for Product of Array Except Self.
*/
