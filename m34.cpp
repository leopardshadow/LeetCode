class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0)
            return {-1, -1};
        
        nums.insert(nums.begin(), -2147483648);
        nums.push_back(2147483647);

        vector<int> ans;
                
        int l = 0, r = nums.size() - 1;
        int m;
        
        // 1. find the left boundary
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] == target && nums[m-1] < target) {
                ans.push_back(m - 1);
                break;
            }
            else if(nums[m] < target) {
                l = m + 1;
            }
            else /*if(nums[m] > target)*/ {
                r = m - 1;
            }
        }
        
        // 2. find the right boundary
        l = m, r = nums.size() - 1;
        
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] == target && nums[m+1] > target) {
                ans.push_back(m - 1);
                break;
            }
            else if(nums[m] > target) {
                r = m - 1;
            }
            else /*if(nums[m] < target)*/ {
                l = m + 1;
            }

        }
        if(ans.size() == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }   
};
