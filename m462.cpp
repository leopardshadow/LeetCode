
// 2022.6.30 Ya! June 

/*
原本以為和平均有關，結果是和中位數有關
---
為什麼是中位數？
不論是中位數還是平均，想法都是找到最後全部陣列都會變成他的那個數，再去計算需要幾次 move
median minimizes L1 norm
L2 norm 的話才是平均
最佳化的東東
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int targ = nums[nums.size() / 2], ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans += abs(targ - nums[i]);
        return ans;
    }
};
/*
Runtime: 21 ms, faster than 26.38% of C++ online submissions for Minimum Moves to Equal Array Elements II.
Memory Usage: 10.7 MB, less than 92.09% of C++ online submissions for Minimum Moves to Equal Array Elements II.
*/
