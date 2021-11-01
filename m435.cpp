/*

*/

class Solution {
public:
    
    struct {
        bool operator()(vector<int> &a, vector<int> &b) const { return a[0] < b[0]; }
    } cmp;
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int ans = 0;
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            
            // overlap 
            if(intervals[i][0] < prevEnd) {
                ans++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else
                prevEnd = intervals[i][1];
        }
        return ans;
    }
};

/*
Runtime: 356 ms, faster than 96.54% of C++ online submissions for Non-overlapping Intervals.
Memory Usage: 89.8 MB, less than 48.15% of C++ online submissions for Non-overlapping Intervals.
*/