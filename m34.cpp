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




/*
[l, r)
基本型：f f f f | t t t
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.size() == 0)
            return ans;
        
        // find left boundary
        int l = 0, r = nums.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        l = min((int)nums.size() - 1, l);
        if (nums[l] == target)
            ans[0] = l;
        
        // find right boundary
        l = 0, r = nums.size();
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] > target)
                r = m;
            else
                l = m + 1;
        }
        if (l - 1 >= 0 && nums[l-1] == target)
            ans[1] = l - 1;

        return ans;
    }
};
/*
Runtime: 10 ms, faster than 73.39% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 13.7 MB, less than 17.99% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
*/
