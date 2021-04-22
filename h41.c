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
the constraint for nums.length:
1 <= nums.length <= 300

so the answer ranges from 1 to 301
(1 - smallest positive number, if 1 not presents in the array, answer is 1;
301 - only 300 numbers, if they are 1..300, 301 is the biggest answer would be)

hence, only needs a record array of size 302 (0- 301)
*/


/*
Runtime: 0 ms, faster than 100.00% of C online submissions for First Missing Positive.
Memory Usage: 5.9 MB, less than 51.82% of C online submissions for First Missing Positive.
*/