// class Solution {
// public:
    
//     bool search(vector<int>& nums, int target, int r, int l) {
//         if(r == l) return nums[r] == target;
//         int m = (r + l) / 2;
//         if(target == nums[m]) return true;
//         if(nums[l] <= nums[r] && target < nums[l] && target > nums[r])
//             return false;
//         return search(nums, target, r, m) || search(nums, target, m+1, l);
//     }
    
//     bool search(vector<int>& nums, int target) {
//         return search(nums, target, 0, nums.size()-1);
//     }
// };

/*
Runtime: 4 ms, faster than 89.33% of C++ online submissions for Search in Rotated Sorted Array II.
Memory Usage: 14 MB, less than 30.26% of C++ online submissions for Search in Rotated Sorted Array II.
*/

/*
他可以改成 iterative 的寫法

一開始我覺得有點不直觀，因為在 recursive 的寫法中，我們有同時搜尋兩邊
但其實切一半後，一定會有一邊是排序的 (斷點只會出現在其中一邊)
這時候就可以判斷 target 在哪一邊
(可以判斷 target 在不在排序好的那邊)
*/

class Solution {
public:    
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while(l <= r) {
            m = (l + r) / 2;
            if(target == nums[m]) return true;

            // for duplicates
            // 這三個數都一樣的話沒辦法比，先移動後再來
            if(nums[l] == nums[m] and nums[m] == nums[r]) {
                l++; r--;
                continue;
            }

            
            if(nums[l] <= nums[m]) { // left is sorted
                if(target < nums[l] || target > nums[m]) // not in left part, should search right
                    l = m + 1;
                else // should search left part
                    r = m - 1;
            }
            else { // right is sorted
                if(target < nums[m] || target > nums[r]) // not in right part, should search left
                    r = m - 1;
                else // should search right part
                    l = m + 1;
            }
        }
        return false;
    }
};

/*
Runtime: 4 ms, faster than 89.33% of C++ online submissions for Search in Rotated Sorted Array II.
Memory Usage: 14 MB, less than 30.26% of C++ online submissions for Search in Rotated Sorted Array II.
*/
