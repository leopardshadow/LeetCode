
// 2022.6.11

/*
如果改成 nums 有可能出現 0 會變得再麻煩一點點
---
用 sliding window 想 TC 表現比較好
先想像全拿，再拔掉一些（加回去），拔掉的要是連續的
於是現在問題變成：找到最長的連續區間，他的區間總合會是 sum(nums) - x
這部分可以用 sliding window 做
一開始 l = 0, r = 0
如果 sum 太小，r++ 加上去
如果 sum 太大，l++ 扣除
如果 sum 等於目標，加進去比較
*/

/*
[ 1, 1, 4, 2, 3]
[11,10, 9, 5, 3] (suffixSums)
  0 --> try to find 5
  1 --> try to find 4
  1 + 1 --> try to find 3
  1 + 1 + 4 --> try to find ...
*/

class Solution {
    
    int binSearch(vector<int>& nums, int start, int targ) {
        int l = start, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == targ)  // stricly decreasing
                return m;
            else if (nums[m] > targ)
                l = m + 1;
            else
                r = m;
        }
        return -1;  // not found
    }
    
public:
    int minOperations(vector<int>& nums, int x) {
        
        int suffixSum = 0;
        vector<int> sufSums(nums.size() + 1);
        sufSums.back() = 0;  // take nothing from the right
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffixSum += nums[i];
            sufSums[i] = suffixSum;
        }
                
        int ans = INT_MAX;
        
        int prefixSum = 0, pos;
        for (int i = 0; i < nums.size(); i++) {
            // cout << prefixSum;
            if ((pos = binSearch(sufSums, i, x - prefixSum)) != -1) {
                ans = min(ans, i + (int)nums.size() - pos);
                // cout << " " << pos;
            }
            // cout << endl;
            prefixSum += nums[i];
        }
        
        if (prefixSum == x)
            ans = min(ans, (int)nums.size());
        
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
Runtime: 605 ms, faster than 25.53% of C++ online submissions for Minimum Operations to Reduce X to Zero.
Memory Usage: 102.9 MB, less than 49.81% of C++ online submissions for Minimum Operations to Reduce X to Zero.
*/
