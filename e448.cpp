// cyclic sort
// https://blog.techbridge.cc/2020/02/16/leetcode-%E5%88%B7%E9%A1%8C-pattern-cyclic-sort/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        while(i < nums.size()) {
            int j = nums[i] - 1;
            if(j < nums.size() && nums[i] != nums[j])
                swap(nums[i], nums[j]);
            else 
                i++;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1)
                ans.push_back(i+1);
        }
        return ans;
    }
};

/*
Runtime: 48 ms, faster than 87.42% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 33.8 MB, less than 53.94% of C++ online submissions for Find All Numbers Disappeared in an Array.
*/