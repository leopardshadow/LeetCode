
// Biweekly Contest 75

/*
就照他題目要求的做~
*/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - 1 - i; j++) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }  
        return nums[0];
    }
};
