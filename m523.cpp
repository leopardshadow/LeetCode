
// 2022.10.26

/*
原本想用 set，因為只要出現第二次就可以回傳 true
但是這樣在 at least two elements 有點麻煩
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        map<int, int> m;
        m[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int x = sum % k;
            if (m.find(x) == m.end())
                m[x] = i + 1;
            else if (m[x] < i)
                return true;
        }
        return false;
    }
};
/*
Runtime: 293 ms, faster than 81.61% of C++ online submissions for Continuous Subarray Sum.
Memory Usage: 114.9 MB, less than 23.41% of C++ online submissions for Continuous Subarray Sum.
*/
