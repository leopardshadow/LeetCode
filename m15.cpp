/*
Notice that the solution set must not contain duplicate triplets.
*/
/*
TLE for now
*/
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         map<int, int> m;
//         map<vector<int>, bool> a_m;
//         vector<vector<int> > ans;
//         int target;
//         // create hash table
//         for(int i = 0; i < nums.size(); i++) {
//             m[nums[i]] = i;
//         }
        
//         // traverse every number in nums
//         for(int i = 0; i < (int)nums.size() - 2; i++) {
//             for(int j = i + 1; j < (int)nums.size() - 1; j++) {
//                 target = -nums[i] - nums[j];
//                 // check if target exists
//                 if(m.find(target) != m.end() && m[target] > j) {
//                     vector <int> temp;
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(target);
//                     sort(temp.begin(), temp.end());
//                     if(a_m.find(temp) == a_m.end()) {
//                         ans.push_back(temp);
//                         a_m[temp] = true;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// the way to remove duplicates is challenging...
// sort and it becomes Leetcode #167 Two Sum II

class Solution {
public:
    
    vector<vector<int>> ans;

    void search(vector<int>& nums, int targ, int start, int end) {
        int l = start + 1,
            r = end;
        
        while(l < r) {
            
//             if(nums[r] == nums[r-1]) {
//                 r--;
//                 continue;
//             }

//             if(nums[l] == nums[l+1]) {
//                 l++;
//                 continue;
//             }

            if(nums[l] + nums[r] == targ) {
                ans.push_back(vector<int>({-targ, nums[l], nums[r]}));
                l++;
                r--;
                
                // remove duplicates
                while (l < r && nums[l] == nums[l-1]) {
                  l++;
                }
                while (l < r && nums[r] == nums[r+1]) {
                  r--;
                }

            
            }
            else if(nums[l] + nums[r] < targ) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        // remove redundant numbers
        // int cnt = 1, curN = nums[0]; 
        // for(vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++) {
        //     if(curN != *it) {
        //         cnt = 1;
        //         curN = *it;
        //     }
        //     else {
        //         cnt++;
        //         if(curN == 0 && cnt > 3) {
        //             cnt--;
        //             nums.erase(it);
        //         }
        //         else if(cnt > 2) {
        //             cnt--;
        //             nums.erase(it);
        //         }
        //     }
        // }
        
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            
            search(nums, -nums[i], i, n-1);
        }
        return ans;
    }    
};

/*
Runtime: 84 ms, faster than 72.73% of C++ online submissions for 3Sum.
Memory Usage: 22 MB, less than 36.36% of C++ online submissions for 3Sum.
*/