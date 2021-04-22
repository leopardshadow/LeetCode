#include <stdbool.h>

int firstMissingPositive(int* nums, int numsSize){
    bool n[302] = {false};
    for(int i = 0; i < numsSize; i++)
        if(nums[i]  >=1 && nums[i] <=301)
        n[ nums[i] ] = true;
    for(int i = 1; i < 302; i++)
        if(!n[i]) return i;
    return 0;
}

/*
Runtime: 0 ms, faster than 100.00% of C online submissions for First Missing Positive.
Memory Usage: 5.9 MB, less than 51.82% of C online submissions for First Missing Positive.
*/