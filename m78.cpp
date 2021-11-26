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



//***************************************************************************//
/*
之前寫過一個作法是 to take or not to take，用 recursive 產生所有可能，今天來換一種寫法
拿或不拿，很自然就會想到 binary，用二進位數字的 1/0 表示取/不取
000
001
010
011
100
101
110
111
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int ss = 0; ss < (1 << n); ss++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (ss & (1 << i))
                    subset.push_back(nums[i]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
Memory Usage: 7 MB, less than 83.01% of C++ online submissions for Subsets.
*/
*/
