class Solution {
public:
    
    vector<vector<int>> ans;
    
    void permute(vector<int> p, unordered_map<int, int> m, int &len) {
        
        if(!len) {
            ans.push_back(p);
        }
            
        
        for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if(it->second > 0) {
                it->second--;
                len--;
                p.push_back(it->first);
                permute(p, m, len);
                p.pop_back();
                it->second++;
                len++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        vector<int> empty;
        int len = nums.size();
        permute(empty, m, len);
        return ans;
    }
};

/*
Runtime: 24 ms, faster than 31.12% of C++ online submissions for Permutations II.
Memory Usage: 15.4 MB, less than 12.13% of C++ online submissions for Permutations II.
*/


// 2022.5.12 
// 偷懶
