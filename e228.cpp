
// 2022.2.28
// Feb LeetCoding Challenge Completed Yay!!

/*
今天雖然是題 easy，但要寫得漂亮也不是隨便寫一寫就好 (?)
---
我最後決定把取出數字和 push 進答案的陣列拆開來做
因為如果後面的數字一直是前面的 +1，答案就會被改變
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        vector<pair<int, int>> v;
        v.push_back({nums[0], nums[0]});
        for(int i = 1; i < nums.size(); i++) {
            if(v.back().second + 1 == nums[i])
                v.back().second = nums[i];
            else
                v.push_back({nums[i], nums[i]});
        }
        for(const pair<int, int> &p : v) {
            if(p.first == p.second)
                ans.push_back(to_string(p.first));
            else
                ans.push_back(to_string(p.first) + 
                              "->" + 
                              to_string(p.second));
        }
        
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
Memory Usage: 6.8 MB, less than 62.02% of C++ online submissions for Summary Ranges.
*/
