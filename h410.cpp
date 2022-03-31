// 2022.3.31

/*
hard 的 DP 實在沒想法啊 QQ，看了討論區和 topic 才有點想法
---
這題根本是三月挑戰的守門員 = =
related topic 有 DP，但其實 binary search + greedy 也行
---
做 binary search，搜尋 subarray 的 largest sum 找到最小值
滿有趣的是一般 binary search 會有 >, =, < 三種不同的情況
<...>
---
在做 binary search 時，上下界很重要，一定要涵蓋到解
其實無腦設成 [0, INT_MAX] 也行，只是會找很久，這裡設定的下界是以陣列中最小的元素 (再大一點的就放不下)，上界則是陣列總和 (所有都分在一起)
*/

class Solution {
    // can we split the array into m parts with each part less than the value k
    bool doable(vector<int>& nums, int M, int k) {
        int i = 0, sum = 0, m = 0;
        while(i < nums.size()) {
            if (sum == 0 && nums[i] > k)  // nums[i] way too large
                return false;
            if (sum + nums[i] > k) {
                sum = 0;
                m++;
            }
            else {
                sum += nums[i];
                i++;
            }
        }
        return m < M;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int right = 0, left = INT_MAX;
        for (int &n : nums) {
            left = min(n, left);
            right += n;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (doable(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
/*
Runtime: 6 ms, faster than 39.54% of C++ online submissions for Split Array Largest Sum.
Memory Usage: 7.2 MB, less than 43.47% of C++ online submissions for Split Array Largest Sum.
*/
