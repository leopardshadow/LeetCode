#include <stdio.h>


int maxSubArray(int* nums, int numsSize){
    int maxSum = -1000000, curSum = 0;
    for(int i = 0; i < numsSize; i++) {
        if(curSum > 0) {
            curSum += nums[i];
        }
        else {
            curSum = nums[i];
        }
        maxSum = (curSum > maxSum ? curSum : maxSum);
    }
    return maxSum;
}

int main(int argc, char const *argv[])
{
    int test1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("test1: %d\n", maxSubArray(test1, 9));

    int test2[] = {1};
    printf("test2: %d\n", maxSubArray(test2, 1));

    int test3[] = {5, 4, -1, 7, 8};
    printf("test3: %d\n", maxSubArray(test3, 5));

    // the question requires at least one number
    int test4[] = {-1};
    printf("test4: %d\n", maxSubArray(test4, 1));

    int test5[] = {-1, 2};
    printf("test5: %d\n", maxSubArray(test5, 2));

    return 0;
}


/*
[-2,1,-3,4,-1,2,1,-5,4]
 -2 1 -2 4  3 5 6  1 5
 -2 1  1 4  4 5 6  6 6
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nmax = nums[0],
            ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            nmax = max(nums[i], nmax + nums[i]);
            ans = max(ans, nmax);
        }
        return ans;
    }
};

/*
Runtime: 96 ms, faster than 55.40% of C++ online submissions for Maximum Subarray.
Memory Usage: 67.7 MB, less than 53.82% of C++ online submissions for Maximum Subarray.
*/