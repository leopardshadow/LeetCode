// cyclic sort
// 想法用 vector 的框框來存有沒有來過
// 這類型題題目都是 [1..n] 所以善用 int 負的那邊 (當然也可以用它 nums 範圍之外的，例如加 100000，每次真的要取值就先 mod)
// 要注意 nums[i] 要取 abs()，因為可能是已經被誰改成負的了

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
            else
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};

/*
Runtime: 40 ms, faster than 97.17% of C++ online submissions for Find All Duplicates in an Array.
Memory Usage: 33.7 MB, less than 45.44% of C++ online submissions for Find All Duplicates in an Array.
*/