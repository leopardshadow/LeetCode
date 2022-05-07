// 2022.5.7

/*
還是好怕 monotone stack，用了其他方法來做。可是好慢 QQ
---
一開始我搞錯題目意思，他只有要求 i < j < k，沒有要求 i, j, k 是三個連續的整數！
但他的 test case 都太小了，這個錯誤的寫法 Example 都會過 = =
---
給一個 j，我們可以確定涵蓋空間最大的 i 是所有 i < j 的數字中，nums[i] 最小的，而在 j 往後的數字中（j < k）的數字中，nums[k] 要介於 nums[i] 和 nums[j] 之間
而 k 存不存在我這裡是用 set 的 lower bound 來做，找到 { nums[k] | j < k } 裡大於等於 Min[i] 的最小值，如果這個最小值存在且他小於 nums[i]，就代表找到了！

	// nums
	// Min

    // 1 2 3 4
    // - 1 1 1
        
    // 3 1 4 2
    // - 3 1 1
        
    // -1  3  2  0
    // -- -1 -1 -1

*/


// 錯誤的解法
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         for (int i = 2; i < nums.size(); i++) {
//             if (nums[i-2] < nums[i] && nums[i] < nums[i-1])
//                 return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        // Min[j] = min { nums[x] | x < j }
        vector<int> Min(nums.size(), INT_MAX - 1);
        for (int i = 1; i < nums.size(); i++) {
            Min[i] = min(nums[i-1], Min[i-1]);
        }
        
        // Set[j] = { nums[x] | j < x } 
        set<int> Set;
        for (int i = nums.size() - 1; i >= 0; i--) {
            
            //
            auto it = Set.lower_bound(Min[i] + 1);
            if (it != Set.end() && *it < nums[i]) {
                return true;
            }
            
            //
            Set.insert(nums[i]);
        }
        
        
        return false;
    }
};
/*
Runtime: 228 ms, faster than 9.42% of C++ online submissions for 132 Pattern.
Memory Usage: 55.5 MB, less than 9.05% of C++ online submissions for 132 Pattern.
*/
