
// Biweekly Contest 78

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        int ans = 0;
        vector<long long> acc(nums.size());   
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            acc[i] = sum;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (acc[i] >= sum - acc[i])
                ans++;
        }
        return ans;
    }
};
