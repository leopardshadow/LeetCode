/*
先依照各區間 start 的順序排好
如果下一個的 end 比上一個的 start 還早，我們知道有重疊了
有重疊，所以需要拔掉兩個區間其中之一 (either 這一個 or 上一個，需要拔掉的計數器 +1)
那要拔掉哪一個呢？ 這裡用 greedy 判斷就好了，把 end 到比較晚的拔掉，留 end 比較早結束的
所以其實我們並沒有真的 “砍掉” 一些區間，而是紀錄上一個 interval 的 end，並更新值
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