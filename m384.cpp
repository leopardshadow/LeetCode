/*
不知道 hint 在說啥
```
The solution expects that we always use the original array to shuffle() else some of the test cases fail. (Credits; @snehasingh31)
```
*/

class Solution {
    vector<int> orig, cur;
public:
    Solution(vector<int>& nums) {
        orig = nums;
        cur = nums;
    }
    
    vector<int> reset() {
        cur = orig;
        return cur;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < cur.size(); i++) {
            swap(cur[i], cur[rand() % cur.size()]);
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


/*
Runtime: 96 ms, faster than 77.09% of C++ online submissions for Shuffle an Array.
Memory Usage: 90.2 MB, less than 68.91% of C++ online submissions for Shuffle an Array.
*/
