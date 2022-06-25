
// 2022.6.25

/*
找到不同點後，可能改前面那個或改後面那個
不知道改哪個？那就都試試看吧
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> incs;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                incs.push_back(i);
                if (incs.size() > 1)
                    return false;
            }
        }
        if (incs.size() == 0)
            return true;
        int x = incs[0];
        return (x - 1 >= 0 ? nums[x-1] : -9999999) <= (x + 1 < nums.size() ? nums[x+1] : 999999) ||
               (x >= 0 ? nums[x] : -9999999) <= (x + 2 < nums.size() ? nums[x + 2] : 999999);
    }
};
/*
Runtime: 33 ms, faster than 75.54% of C++ online submissions for Non-decreasing Array.
Memory Usage: 27.1 MB, less than 12.14% of C++ online submissions for Non-decreasing Array.
*/
