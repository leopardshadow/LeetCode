
// 2022.4.3

/*
看了討論區，原來 next permutation 類的題目要這樣做
---
一個注意的地方是因為我們找的是單調數列，所以他本身就已經是排序好的，不用 sort
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k, j;
        // find the longest **non-increasing** suffix sequence, e.g. 1 2 [4 3 3 0]
        //                                                             k         
        //                                                                    j
        //                                                           1 3 [4 3 2 0] ... swap nums[k], nums[j]
        //                                                           1 3 [0 2 3 4] ... reverse the interval
        for (k = nums.size() - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1])
                break;
        }
        if (k < 0)  // cases like 4 3 2 1, the whole sequence is non-increasing
            reverse(nums.begin(), nums.end());
        else {
            for (j = nums.size() - 1; j > k; j--) {
                if (nums[j] > nums[k])
                    break;
            }
            swap(nums[j], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
/*
Runtime: 7 ms, faster than 51.84% of C++ online submissions for Next Permutation.
Memory Usage: 12.1 MB, less than 75.54% of C++ online submissions for Next Permutation.
*/
