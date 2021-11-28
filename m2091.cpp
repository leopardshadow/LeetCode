// // Weekly Contest 269

class Solution {
    int min(int a, int b) {
        return a < b ? a : b;
    }
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIndex = 0, minIndex = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[maxIndex])
                maxIndex = i;
            if(nums[i] < nums[minIndex])
                minIndex = i;
        }
        // DO NOT need this (covered below)
        // if(maxIndex == minIndex)
        //     return min(maxIndex, nums.size() - 1 - maxIndex);
        
        int rmMinFront = minIndex + 1, rmMinEnd = nums.size() - minIndex;
        int rmMaxFront = maxIndex + 1, rmMaxEnd = nums.size() - maxIndex;
        return min(min(rmMinFront, rmMinEnd) + min(rmMaxFront, rmMaxEnd), 
                   min(  max(rmMinFront, rmMaxFront), 
                         max(rmMinEnd,   rmMaxEnd)));
    }
};

/*
Runtime: 256 ms, faster than 6.67% of C++ online submissions for Removing Minimum and Maximum From Array.
Memory Usage: 88.2 MB, less than 6.67% of C++ online submissions for Removing Minimum and Maximum From Array.
*/
