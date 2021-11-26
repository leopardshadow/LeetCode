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


//***************************************************************************//

// 2021.11.26

/*
這次試了不加 boundary 的作法，好麻煩啊
加 boundary 還是比較簡單，就算如果他數值的範圍是 INT_MIN 到 INT_MAX 也沒關係，我先確認頭、尾不是 INT_MIN 和 INT_MAX 就可以插入了
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // // I'don;t like this method :(, insert some boundary is more intuitive
        // bugs here
        if (nums[0] >= target)
            return 0;
        if (nums.back() == target)
            return nums.size() - 1;
        else if (nums.back() < target)
            return nums.size();
        if(nums.size() == 2 && target > nums[0] && target < nums[1])
            return 1;

        // nums.insert(nums.begin(), -1000000);
        // nums.insert(nums.end(), 1000000);
        
        int l = 1, r = nums.size() - 2, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m ;
            else if (nums[m] < target && nums[m+1] > target)
                return m + 1;
            else if (nums[m-1] < target && nums[m] > target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else 
                l = m + 1;
        }
        return -1;  // never return this
    }
};

/*
Runtime: 8 ms, faster than 19.38% of C++ online submissions for Search Insert Position.
Memory Usage: 9.8 MB, less than 22.57% of C++ online submissions for Search Insert Position.
*/
