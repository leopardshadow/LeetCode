// Weekly Contest 269

/*
這題當然可以直接排序後找 index，TC 是 O(n log n)
但是其實 O(n) 就可以了，只要紀錄比 target 小、等於和比 target 大的數量就行
index 再從比 target 小和等於的數量生出來 (比 target 大其實用不到，下面多寫了)
*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0, eq = 0, bigger = 0;
        for(int n : nums) {
            if(n < target)
                smaller++;
            else if(n == target)
                eq++;
            else
                bigger++;
        }
        vector<int> ans;
        for(int i = 0; i < eq; i++)
            ans.push_back(smaller + i);
        return ans;
    }
};

/*
Runtime: 12 ms, faster than 33.33% of C++ online submissions for Find Target Indices After Sorting Array.
Memory Usage: 11.7 MB, less than 55.56% of C++ online submissions for Find Target Indices After Sorting Array.
*/
