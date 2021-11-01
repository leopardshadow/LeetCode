class Solution {
public:
    
    bool search(vector<int>& nums, int target, int r, int l) {
        if(r == l) return nums[r] == target;
        int m = (r + l) / 2;
        if(target == nums[m]) return true;
        if(nums[l] <= nums[r] && target < nums[l] && target > nums[r])
            return false;
        return search(nums, target, r, m) || search(nums, target, m+1, l);
    }
    
    bool search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }
};

/*
Runtime: 4 ms, faster than 89.33% of C++ online submissions for Search in Rotated Sorted Array II.
Memory Usage: 14 MB, less than 30.26% of C++ online submissions for Search in Rotated Sorted Array II.
*/