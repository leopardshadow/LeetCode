
// 2022.5.3

/*
TC: O(n)
SC: O(n)
---
x, ...
---
2 6 4 8 10  9 15
2 4 4 9  9 15 15 (包含自己往後看最小的)
 (a)
2 6 6 8 10 10 15 (包含自己往前看最小的)
          (b)
a / b 分別是沒有排序 subarray 的起點和終點
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), a = n, b = 0;
        vector<int> smaller(n), bigger(n);
        
        // small
        int nmin = nums.back();
        for (int i = n - 1; i >= 0; i--) {
            nmin = min(nmin, nums[i]);
            smaller[i] = nmin;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != smaller[i]) {
                a = i;
                break;
            }
        }

        // big
        int nmax = nums[0];
        for (int i = 0; i < n; i++) {
            nmax = max(nmax, nums[i]);
            bigger[i] = nmax;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] != bigger[i]) {
                b = i;
                break;
            }
        }

        return max(0, b - a + 1);
    }
};
/*
Runtime: 39 ms, faster than 64.19% of C++ online submissions for Shortest Unsorted Continuous Subarray.
Memory Usage: 28.2 MB, less than 11.86% of C++ online submissions for Shortest Unsorted Continuous Subarray.
*/
