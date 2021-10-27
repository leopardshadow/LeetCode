/*
the method shown below seems not to be what it want =w=
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[3] = {0, 0, 0,};
        for(const auto n : nums)
            c[n]++;
        
        int i = 0;
        while(c[0]) {
            nums[i] = 0;
            i++;
            c[0]--;
        }
        while(c[1]) {
            nums[i] = 1;
            i++;
            c[1]--;
        }

        while(c[2]) {
            nums[i] = 2;
            i++;
            c[2]--;
        }

    }
};
/*
Runtime: 4 ms, faster than 45.19% of C++ online submissions for Sort Colors.
Memory Usage: 8.3 MB, less than 23.69% of C++ online submissions for Sort Colors.
*/