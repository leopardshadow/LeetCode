class Solution {
public:
    int search(vector<int>& nums, int target, int l, int r) {
        
        if(l == r) {
            if(nums[l] == target) return l;
            else return -1;
        }
        // it is sorted
        else if(nums[l] < nums[r] &&
                (target < nums[l] || target > nums[r]))
            return -1;

        int m = (l + r) / 2;
        return max(search(nums, target, l, m), search(nums, target, m+1, r));
    }

    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};

/*
Runtime: 8 ms, faster than 23.33% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 11.1 MB, less than 75.05% of C++ online submissions for Search in Rotated Sorted Array.
*/