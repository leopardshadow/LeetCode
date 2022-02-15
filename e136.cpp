
int singleNumber(int* nums, int numsSize){
    int ans = 0;
    for(int i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }
    return ans;
}

/*
Runtime: 25 ms, faster than 40.03% of C online submissions for Single Number.
Memory Usage: 7.4 MB, less than 32.49% of C online submissions for Single Number.
*/



// 2022.2.15  元宵節

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(const int &n : nums)
            ans ^= n;
        return ans;
    }
};

/*
Runtime: 20 ms, faster than 76.93% of C++ online submissions for Single Number.
Memory Usage: 16.9 MB, less than 50.83% of C++ online submissions for Single Number.
*/
