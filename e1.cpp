class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector <int> ans;
        map<int, int> mapping;

        for(int i = 0; i < nums.size(); i++)
            mapping[nums[i]] = i;
        
        
        for(int i = 0; i < nums.size(); i++) {
            
            // check if (target - nums[i]) in nums 
            map<int, int>::iterator iter = mapping.find(target - nums[i]);
            if(iter != mapping.end() && iter->second != i) {
                ans.push_back(i);
                ans.push_back(iter->second);
                return ans;
            }
        }
        return ans; // will never execute this line, since gurantee exactly one solution
    }
};

/*
Runtime: 24 ms, faster than 45.34% of C++ online submissions for Two Sum.
Memory Usage: 12.3 MB, less than 7.01% of C++ online submissions for Two Sum.
*/