/*
for each element in the set, you can either choose or not to choose
*/

#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > ans;
    vector<int> nums;
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        
        this->nums = nums;
        
        vector<int> empty_set;
        gen_subsets(empty_set, 0);
        
        return ans;
    }
    
    void gen_subsets(vector<int> sset, int i) {
        
        if(i == nums.size()) {
            ans.push_back(sset);
            return;
        }
        // not to choose
        gen_subsets(sset, i+1);
        
        // choose
        sset.push_back(nums[i]);
        gen_subsets(sset, i+1);
    }
};

/*
Runtime: 7 ms, faster than 16.49% of C++ online submissions for Subsets.
Memory Usage: 15.8 MB, less than 15.60% of C++ online submissions for Subsets.
*/