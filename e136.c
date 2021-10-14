
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