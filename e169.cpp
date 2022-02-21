
// 2022.2.21

/*
如果沒有任何要求就一個 map 就好，全部跑過數次數
但是題目特別說了有 linear time O(1) space 的作法
這可以用 Boyer–Moore majority 解
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        for(const int &n : nums)
            um[n]++;
        for(const auto &it : um)
            if(it.second > nums.size() / 2)
                return it.first;
        return -1;  // should never return this
    }
};
/*
Runtime: 41 ms, faster than 15.87% of C++ online submissions for Majority Element.
Memory Usage: 19.6 MB, less than 52.27% of C++ online submissions for Majority Element.
*/


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
        
//     }
// };
