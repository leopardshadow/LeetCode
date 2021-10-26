/*
Notice that the solution set must not contain duplicate triplets.
*/
/*
TLE for now
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> m;
        map<vector<int>, bool> a_m;
        vector<vector<int> > ans;
        int target;
        // create hash table
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        
        // traverse every number in nums
        for(int i = 0; i < (int)nums.size() - 2; i++) {
            for(int j = i + 1; j < (int)nums.size() - 1; j++) {
                target = -nums[i] - nums[j];
                // check if target exists
                if(m.find(target) != m.end() && m[target] > j) {
                    vector <int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(target);
                    sort(temp.begin(), temp.end());
                    if(a_m.find(temp) == a_m.end()) {
                        ans.push_back(temp);
                        a_m[temp] = true;
                    }
                }
            }
        }
        return ans;
    }
};