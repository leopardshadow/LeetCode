// leads to TLE
// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int prod;
//         int ans = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             prod = 1;
//             for(int j = 0; i + j < nums.size(); j++) {
//                 prod *= nums[i + j];
//                 if(prod < k)
//                     ans++;
//                 else
//                     break;
//             }
//         }
//         return ans;
//     }
// };


/*
Hint. sliding window
用 left 和 right 兩個指針記錄當下 window 的位置，讓 right 慢慢往右乘，如果乘積滿足 "less than K"，就代表這個 sliding window 內所有元素都符合 "less than K"
加的 (left - right + 1) 代表的是以 right 為尾巴有幾種可能
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1) return 0;
        
        int right = 0, left = 0, prod = 1, ans = 0;
        
        while(right < nums.size()) {
            
            prod *= nums[right];
            
            while(prod >= k) {
                prod /= nums[left];
                left++;
            }
            
            ans += (right - left + 1);
            right++;
        }
        
        return ans;
    }
};

/*
Runtime: 64 ms, faster than 96.52% of C++ online submissions for Subarray Product Less Than K.
Memory Usage: 61.3 MB, less than 70.18% of C++ online submissions for Subarray Product Less Than K.
*/