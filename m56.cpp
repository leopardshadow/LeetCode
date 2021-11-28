class Solution {
public:
    
    struct {
        bool operator()(vector<int> &a, vector<int> &b) const { return a[0] < b[0]; }
    } cmp;
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // sort by its start
        sort(intervals.begin(), intervals.end(), cmp);
        
        // after sorting, there are 3 possibilities
        /*
        aaaaaa   | aaaaa       |  aaa
          bb     |    bbbbbbb  |         bbbbb
        --- 1 ---|----- 2 -----|------ 3 ------
        */
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);  // the begin should be processed 0w0
        for(int i = 1; i < intervals.size(); i++) {
            
            // case 1
            if(intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            
            // case 2 & 1
            else if(intervals[i][0] <= ans.back()[1])
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
        return ans;
    }
};

/*
Runtime: 30 ms, faster than 33.43% of C++ online submissions for Merge Intervals.
Memory Usage: 14.3 MB, less than 56.68% of C++ online submissions for Merge Intervals.
*/


//***************************************************************************//
// Review: 2021.11.28 before G VO

/*
嘗試了 lambda function 比較大小 XD
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort by its start time
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            // merge!
            if(intervals[i][0] <= ans.back()[1])
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            // disjoint
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
