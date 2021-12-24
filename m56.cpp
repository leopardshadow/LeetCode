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




//******************************************************************************//
// 2021.12.24 平安夜~~

/*
又是寫過的題目R，最近都只寫每日題，題數沒增加XD
---
interval 題目的模式好像都蠻固定的
---
一開始我少加 max ...
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};

/*
Runtime: 20 ms, faster than 62.64% of C++ online submissions for Merge Intervals.
Memory Usage: 14.1 MB, less than 94.91% of C++ online submissions for Merge Intervals.
*/

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
