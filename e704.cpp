class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m;
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};

/*
Runtime: 36 ms, faster than 69.74% of C++ online submissions for Binary Search.
Memory Usage: 27.6 MB, less than 61.69% of C++ online submissions for Binary Search.
*/



// 2022.3.26

/*
沒有偷看，但是和上次寫的幾乎一模一樣 XD
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};
/*
Runtime: 96 ms, faster than 5.15% of C++ online submissions for Binary Search.
Memory Usage: 27.5 MB, less than 63.85% of C++ online submissions for Binary Search.
*/



/*
嘗試用了 <algorithm> 的 find
---
從 iterator 拿到 index 的寫法：it - vec.begin()
---
不過 find 是順序得找，不是二分搜尋。可能是測資太小，居然比我寫得二分搜快 = =
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if (it == nums.end())
            return -1;
        else
            return it - nums.begin();
    }
};
/*
Runtime: 49 ms, faster than 57.25% of C++ online submissions for Binary Search.
Memory Usage: 27.6 MB, less than 13.43% of C++ online submissions for Binary Search.
*/
