/*
key: 
往下分，直到他是排序好的，return 排序好的最左邊的值 (最小值)
合併時選左右最小的
*/

class Solution {
public:
    int findMin(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];
        else if(nums[l] < nums[r]) // [l, r] is sorted
            return nums[l];
        else {
            int m = (l + r) / 2;
            return min(findMin(nums, l, m), findMin(nums, m+1, r));   // m + 1 !!!!!
        }
    }

    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

};