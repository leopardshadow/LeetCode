
// 2022.5.2

/*
這裡的 l 和 ｒ 代表的是確定是偶、奇的邊界外的
---
      3 1 2 4
even |l     r| odd
(swap)
      4 1 2 3
even   |l r|   odd
(swap)
even    r|l    odd
(Done)
---
一開始寫成 n = size - 1; 一直在找迴圈內到底錯在哪 ...
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            
            if (l < n && nums[l] % 2 == 0)
                l++;
            if (r >= 0 && nums[r] % 2 == 1)
                r--;
            
            if (l >= r)
                break;
            
            if (nums[l] % 2 == 1 && nums[r] % 2 == 0)
                swap(nums[l], nums[r]);
        }
        return nums;
    }
};
