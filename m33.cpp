// D&C

class Solution {
public:
    int search(vector<int>& nums, int target, int l, int r) {
        
        if(l == r) {
            if(nums[l] == target) return l;
            else return -1;
        }
        // it is sorted and target out of range
        else if(nums[l] < nums[r] &&
                (target < nums[l] || target > nums[r]))
            return -1;

        int m = (l + r) / 2;
        if(target == nums[m]) return m;  // 加速!! 不然他一定要等到 l == r 才能回傳找到的
        return max(search(nums, target, l, m), search(nums, target, m+1, r));
    }

    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 11.1 MB, less than 29.52% of C++ online submissions for Search in Rotated Sorted Array.
*/