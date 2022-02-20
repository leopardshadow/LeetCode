
// 2022.2.20

/*
這類 interval 的題目遇到 SOP 第一步就是先 sort，通常我會依開始時間排序
排序過後兩個 interval 之間的關係可以被減少
這題 size 超小，硬爆都可以
*/

// O(n^2)
// 其實要這樣寫乾脆不要 sort..
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] < b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] > b[1];
            else
                return false;
        });
        
        int ans = intervals.size();

        int farthest = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][1] <= farthest)
                ans--;
            farthest = max(farthest, intervals[i][1]);
        }
        
        return ans;
    }
};
/*
Runtime: 51 ms, faster than 25.44% of C++ online submissions for Remove Covered Intervals.
Memory Usage: 11.2 MB, less than 89.47% of C++ online submissions for Remove Covered Intervals.
*/

// O(n log n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] < b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] > b[1];
            else
                return false;
        });
        
        int ans = intervals.size();
        int farthest = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][1] <= farthest)
                ans--;
            farthest = max(farthest, intervals[i][1]);
        }
        
        return ans;
    }
};
/*
Runtime: 56 ms, faster than 22.59% of C++ online submissions for Remove Covered Intervals.
Memory Usage: 11.3 MB, less than 89.47% of C++ online submissions for Remove Covered Intervals.
*/
