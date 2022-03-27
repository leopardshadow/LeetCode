
// Weekly Contest 286

/*
其實我覺得 contest 中的 easy 題都比較偏向閱讀測驗，要小心題目的敘述：他到底要求什麼
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> m1, m2;
        for(int &n : nums1)
            m1[n]++;
        for(int &n : nums2)
            m2[n]++;
        
        vector<vector<int>> ans(2);
        
        for(auto it : m1) {
            if(m2[it.first] == 0) {
                ans[0].push_back(it.first);
            }      
        }
        
        for(auto it : m2) {
            if(m1[it.first] == 0) {
                ans[1].push_back(it.first);
            }
        }
        
        return ans;      
    }
};
/*
Runtime: 80 ms, faster than 44.44% of C++ online submissions for Find the Difference of Two Arrays.
Memory Usage: 36.9 MB, less than 11.11% of C++ online submissions for Find the Difference of Two Arrays.
*/
