
// 2022.11.11

/*
2-pointer
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
                j++;
            }
            else {
                j++;
            }
        }
        return i + 1;
    }
};
/*
Runtime: 18 ms, faster than 77.30% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 18.3 MB, less than 92.95% of C++ online submissions for Remove Duplicates from Sorted Array.
*/
