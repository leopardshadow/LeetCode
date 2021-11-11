class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int ans = 1;
        for(const auto n : nums) {
            sum += n;
            if(sum <= 0) {
                ans = max(ans, abs(sum) + 1);
            }
        }
        return ans;
    }
};
