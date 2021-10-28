/*
2 pointer
一開始我的想法是先找到 0，再依序從那個往左往右找，但題目不一定會出現 0
可以一樣從頭尾找，加入答案的 vector 時放在最後面 ()
*/
class Solution {
public:
    static int square(int x) {
        return x * x;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector <int> ans;

        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            if(abs(nums[l]) >= abs(nums[r])) {
                ans.insert(ans.begin(), square(nums[l]));
                l++;
            }
            else {
                ans.insert(ans.begin(), square(nums[r]));
                r--;
            }
        }
        return ans;
    }
};

/*
Runtime: 568 ms, faster than 5.03% of C++ online submissions for Squares of a Sorted Array.
Memory Usage: 26.9 MB, less than 27.38% of C++ online submissions for Squares of a Sorted Array.
*/