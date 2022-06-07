
// 2022.6.7

/*
題目的 follow-up 是 O(m+n) 時間，關鍵是從尾巴開始做，從頭做的話要一直往後移
---
2-pointer
---
nums1[i--] = nums1[i1--];
好像也可以，但是順序上好麻煩 @@ 不喜歡 :(
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1, i2 = n - 1, i = m + n - 1;
        while (i1 >= 0 && i2 >= 0) {
            if (nums2[i2] >= nums1[i1])
                nums1[i] = nums2[i2--];
            else
                nums1[i] = nums1[i1--];
            i--;
        }
        while (i2 >= 0) {
            nums1[i] = nums2[i2--];
            i--;
        }
    }
};
