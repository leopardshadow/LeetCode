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
            // 中間有隔一個的話，就可以拿前面最大的來用，一定不會連續！！ 
            // (不過這裡比較直觀的方式是用 for 迴圈往前檢查)
            nmax[i - 1] = ans;  // ---------> key to [2, 1, 1, 2]
            ans = max(ans, nmax[i]);
        }
        return ans;
    }
};

/////////////////////////

// DP D3

/*
0 1 2
2 1 1 2
2 1 3 
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> table(nums.size(), 0);
        table[0] = nums[0];
        table[1] = nums[1];
        for(int i = 2; i < nums.size(); i++) {
            table[i] = max(table[i-1],
                           table[i-2] + nums[i]);
            // this is not very intuitive to me ... QQ
            table[i-1] = max(table[i-1], table[i-2]);
        }
        return table.back();
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
Memory Usage: 7.8 MB, less than 42.40% of C++ online submissions for House Robber.
*/

/////////////////////////
// 改寫成不存整張 table 的話

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        int dp2 = nums[0],  // one previous
            dp1 = nums[1],  // two preiovus
            dp;
        for(int i = 2; i < nums.size(); i++) {
            dp = max(dp1,
                     dp2 + nums[i]);
            // this is not very intuitive to me ... QQ
            dp2 = max(dp1, dp2);
            dp1 = dp;
        }
        return dp;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
Memory Usage: 7.6 MB, less than 72.71% of C++ online submissions for House Robber.
*/

/////////////////////////
// 這樣寫法比較直觀 !!!!

/*
2. 7  9. 3. 1. 
2. 7  11 11.12
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        int dp2 = nums[0],  // one previous
            dp1 = max(nums[0], nums[1]),  // two preiovus
            dp;
        for(int i = 2; i < nums.size(); i++) {
            dp = max(dp1, dp2 + nums[i]);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
Memory Usage: 7.7 MB, less than 72.71% of C++ online submissions for House Robber.
*/
