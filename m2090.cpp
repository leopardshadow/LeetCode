// Weekly Contest 269

// sliding window

/*
透過 sliding window，可以不用重複計算加總的部分
---
要注意 index 的邊界，像這題就要特別注意 Example 2, 3 的那些 corner cases
---
一開始交的時候是 WA，因為 integer overflow 了，把 sum 改成 long long 就過了
確實從他的題目敘述裡面：n <= 10^5, k <= 10^5 可以知道可能會超過 int32 的表示範圍
INT_MAX 只有 2,147,483,647
一開始沒注意到
---

這題一開始卡住，後來才發現是 signed / unsigned 的問題
the implicit casting of signed to unsigned leads to some non-intuitive behavior

https://github.com/leopardshadow/CSAPP-Lab/blob/main/ch2/unsigned2signed.c

一句話：unsugned 不要隨便跟 signed 比較、加、減，要的話請自己轉型
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        nums.push_back(0);
        vector<int> ans(nums.size() - 1, -1);
        
        long long sum = 0;  // ...
        for(int i = 0; i < 2*k + 1 && i < nums.size(); i++)
            sum += nums[i];
        
        for(int i = k; i < (int)ans.size() - k; i++) {
            ans[i] = sum / (2 * k + 1);
            sum -= nums[i-k];
            sum += nums[i+k+1];
        }
        return ans;
    }
};

/*
Runtime: 315 ms, faster than 14.29% of C++ online submissions for K Radius Subarray Averages.
Memory Usage: 129.8 MB, less than 100.00% of C++ online submissions for K Radius Subarray Averages.
*/
