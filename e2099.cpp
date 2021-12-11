// Biweekly Contest 67

/*
感覺這題根本考 STL sort 的操作 XDD
一開始針對大小排序，接著再依照他們的 index 排序，弄成 "subsequence"
這樣第一個步驟的 TC 是 n log n，第二步是 k log k
*/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<pair<int, int>> t;
        
        for(int i = 0; i < nums.size(); i++) {
            t.push_back({i, nums[i]});
        }
        
        sort(t.begin(), t.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });
        
        sort(t.begin(), t.begin() + k);
        
        vector<int> ans(k);
        
        for(int i = 0; i < k; i++) {
            ans[i] = t[i].second;
        }
        
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Find Subsequence of Length K With the Largest Sum.
Memory Usage: 9.4 MB, less than 92.31% of C++ online submissions for Find Subsequence of Length K With the Largest Sum.
*/
