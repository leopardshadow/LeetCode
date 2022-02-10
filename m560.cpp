
// 2022.2.10

/*
原本看題目以為可以用 sliding window 解
---
我一開始的寫法，只有對正數的陣列才正確，沒注意到負數也在範圍內
當現在 sum 比目標的 k 小時，原本的想法是只要往後取就會變大
但是當有負數時，丟掉前面的和往後取都有可能讓總合變大，出現了兩種可能
這個寫法在
[-1,-1,1]
0
這樣簡單但是有正、有負的測資就會出錯
---
而且 l, r 的範圍要很小心
---
另外，這個 continuous subarrays 必須要有東西 (len >= 1)，也要判斷
---
[l, r)
. . . . .
l x x x x r
[         )
===
這題論分類是算在 prefix sum，昨天的 daily 也是 prefix sum
把 [a, b] (a < b) 這段連續的 subarray 拆成 [0, b] - [0, a)
所以有存的子陣列和只有 [0, x], x = 0, 1, 2, ..., size - 1
k = sum [0, b] - sum [0, a]
sum [0, a] = sum [0, b] - k
---
ans += m[sum-k]
其實這行先用 find 判斷，有東西才加感覺是比較安全的做法 (532. K-diff Pairs in an Array 遇到的問題!!)
*/

// 應該是只有正的會對
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l = 0, r = 1, sum = nums[0], ans = 0;
        while(l < r && r <= nums.size()) {
            if(sum == k) {
                ans++;
                sum -= nums[l];
                l++;
            }
            else if(sum < k) {
                sum += nums[r];
                r++;
            }
            else {  // sum > k
                sum -= nums[l];
                l++;
            }
        }
        return ans;
    }
};


// 正確的做法
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;  // for [0, x]
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {  // iterate b
            sum += nums[i];
            ans += m[sum-k];  // add the number of valid a to ans
            m[sum]++;
        }
        return ans;
    }
};

/*
Runtime: 162 ms, faster than 22.13% of C++ online submissions for Subarray Sum Equals K.
Memory Usage: 41.7 MB, less than 16.23% of C++ online submissions for Subarray Sum Equals K.
*/
