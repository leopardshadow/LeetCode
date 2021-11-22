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


/*
這種題目有一些變形，像這題是**至少要取一個**，所以答案可能是負的
如果是可以不取，寫起來又會有點不同
感覺也可以用 sliding window 的感覺寫
好怕 DP 的題目 QQ
*/


// DP D5

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], curSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            curSum = curSum + nums[i];
            if(curSum >= 0) {
                curSum = max(nums[i], curSum);
                ans = max(ans, curSum);
            }
            else {
                curSum = nums[i];
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};

/*Runtime: 104 ms, faster than 62.46% of C++ online submissions for Maximum Subarray.
Memory Usage: 67.8 MB, less than 11.26% of C++ online submissions for Maximum Subarray.
*/



Runtime: 104 ms, faster than 66.20% of C++ online submissions for Maximum Subarray.
Memory Usage: 67.8 MB, less than 53.17% of C++ online submissions for Maximum Subarray.
