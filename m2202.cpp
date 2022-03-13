
// Weekly Contest 284
// 2022.3.13

/*
greedy
但是寫 greedy rule 時要小心
吃了一個 WA，因為沒處理到 pile 只有一個東西時，他只能拿放拿放... 循環
*/

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        if(nums.size() == 1 && k % 2 == 1)
            return -1;
        
        int ans = -1;
        
        for(int i = 0; i < k - 1 && i < nums.size(); i++)
            ans = max(ans, nums[i]);
        
        if(k < nums.size())
            ans = max(ans, nums[k]);
        
        return ans;
    }
};

/*
Runtime: 231 ms, faster than 12.50% of C++ online submissions for Maximize the Topmost Element After K Moves.
Memory Usage: 63.3 MB, less than 100.00% of C++ online submissions for Maximize the Topmost Element After K Moves.
*/
