
/*
[0,1,0,3,12]

*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0,  // search zeros
            nt0 = 0;  // search non-zero
        
        do {
            // search non-zero
            while(nt0 < nums.size() && nums[nt0] == 0)
                nt0++;
            
            while(cur < nums.size() && nums[cur] != 0)
                cur++;

            if(nt0 == nums.size() || cur == nums.size()) break;
            
            nums[cur] = nums[nt0];

            cur++;
            nt0++;
            
        } while(nt0 < nums.size() && cur < nums.size());
        
        for(cur = cur - 1; cur < nums.size(); cur++) {
            nums[cur] = 0;
        }
    }
};