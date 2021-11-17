/*
變形一點點的 binary search
一開始想的時候有點錯誤，假如找不到 (i.e. nums[i] < target && nums[i+1] > target)
那要插在 i 後面一個，也就是 i + 1 的位置
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.insert(nums.begin(), -1000000);
        nums.push_back(1000000); // push a biggest value to deal with corner cases
        int l = 0, r = nums.size() - 1;
        int mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(target == nums[mid])
                return mid - 1;
            if(nums[mid] < target && nums[mid+1] > target)
                return mid;
            if(nums[mid] > target && nums[mid-1] < target)
                return mid - 1;
            if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1; // never return this
    }
};

/*
Runtime: 4 ms, faster than 80.55% of C++ online submissions for Search Insert Position.
Memory Usage: 9.6 MB, less than 93.95% of C++ online submissions for Search Insert Position.
*/
