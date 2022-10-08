
// 2022.10.8

/*
2-pointer!
*/

class Solution {
    int diff(int a, int b) {
        return abs(a - b);
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2], n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (diff(sum, target) < diff(ans, target))
                    ans = sum;
                if (sum == target)
                    break;
                if (sum > target)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};
/*
Runtime: 623 ms, faster than 24.81% of C++ online submissions for 3Sum Closest.
Memory Usage: 16.3 MB, less than 48.38% of C++ online submissions for 3Sum Closest.
*/
