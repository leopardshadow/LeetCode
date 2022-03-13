
// Weekly Contest 284
// 2022.3.13

/*
我用 set
*/

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        vector<int> keys;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == key)
                keys.push_back(i);
        
        set<int> s;
        for(int &key : keys) {
            for(int i = max(0, key - k); i < min((int)nums.size(), key + k + 1); i++)
                s.insert(i);
        }
        
        vector<int> ans;
        for(auto i : s)
            ans.push_back(i);
        return ans;
    }
};
