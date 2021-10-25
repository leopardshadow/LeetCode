/*
n = nums.size()
_ _ _ .. _ - n positions to place numbers
for each postion, you can place ...
*/

class Solution {
private:
    vector<vector<int> > ans;
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> empty_perm;
        gen_perm(empty_perm, nums);
        return ans;
    }
    
    void gen_perm(vector<int> cur_perm, vector<int> num_left) {
        if(num_left.empty()) {
            ans.push_back(cur_perm);
            return;
        }
        for(int i = 0; i < num_left.size(); i++) {
            int num = num_left[0];
            
            num_left.erase(num_left.begin());
            cur_perm.push_back(num);
            
            gen_perm(cur_perm, num_left);
            
            num_left.push_back(num);
            cur_perm.erase(cur_perm.begin() + cur_perm.size() - 1);
        }
    }
};

/*
Runtime: 3 ms, faster than 76.71% of C++ online submissions for Permutations.
Memory Usage: 8.7 MB, less than 12.45% of C++ online submissions for Permutations.
*/