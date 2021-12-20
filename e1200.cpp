// 2021.12.20

/*
題目雖然是說 minimum absolute difference "between two elements in the array"
任意兩個，但其實要找 min 的話，先把 arr 排序後，這個 minDiff 只會發生在 arr 的隔壁 elements 間
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        int diff, minDiff = INT_MAX;
        vector<vector<int>> ans;
        
        for(int i = 1; i < arr.size(); i++) {
            diff = arr[i] - arr[i - 1];
            if(diff == minDiff) {
                ans.push_back({arr[i-1], arr[i]});
            }
            else if(diff < minDiff) {
                ans.clear();
                ans.push_back({arr[i-1], arr[i]});
                minDiff = diff;
            }
        }
        return ans;
    }
};

/*
Runtime: 64 ms, faster than 81.88% of C++ online submissions for Minimum Absolute Difference.
Memory Usage: 32.3 MB, less than 42.86% of C++ online submissions for Minimum Absolute Difference.
*/
