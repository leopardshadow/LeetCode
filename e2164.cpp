
// Leetcode 某週競賽題

/*
以下的作法多用了空間來存 odd/even 的陣列
如果是用 selection sort，把 i+=1 改成 i+=2 就不用多花空間來存!
*/

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> evens, odds, ans;
        for(int i = 0; i < nums.size(); i += 2)   
            evens.push_back(nums[i]);
        for(int i = 1; i < nums.size(); i += 2)   
            odds.push_back(nums[i]);
        sort(odds.rbegin(), odds.rend());
        sort(evens.begin(), evens.end());
        for(int i = 0; i < odds.size(); i++) {
            ans.push_back(evens[i]);
            ans.push_back(odds[i]);
        }
        if(nums.size() % 2 == 1)
            ans.push_back(evens.back());
        return ans;
    }
};

/*
Runtime: 12 ms, faster than 44.98% of C++ online submissions for Sort Even and Odd Indices Independently.
Memory Usage: 12.3 MB, less than 18.16% of C++ online submissions for Sort Even and Odd Indices Independently.
*/
