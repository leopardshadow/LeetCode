/*
https://blog.techbridge.cc/2020/01/16/leetcode-%E5%88%B7%E9%A1%8C-pattern-merge-intervals/
他的截圖裡是 hard 難度，但我現在看的是 medium，原來難易度還會調整 XD
可以分成三個部分來處理：
---------------------------
1. 比新加入的區間沒關係(小的)
2. 需要合併的
3. 比新加入的區間沒關係(大的)

這個順序好容易搞錯啊
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        vector<int> interv;

        // start_i already in ascending order
        
        int i = 0;
        // 1：如果要新加入的頭比現在這個的尾大，那他們兩個沒關係，可以直接 push 進答案
        while(i < intervals.size() && newInterval[0] > intervals[i][1]) {
            ans.push_back(intervals[i]);
            i++;
        }
        // 2：如果有連在一起，就繼續擴大
        // (有連在一起 = 新加入的尾有接到這個的頭 = newTail >= iHead)
        while(i < intervals.size() &&  newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        // 3
        while(i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 99.84% of C++ online submissions for Insert Interval.
Memory Usage: 17.1 MB, less than 76.42% of C++ online submissions for Insert Interval.
*/