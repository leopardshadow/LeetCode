
// 2022.9.11

/*
偷看解答
---
先依 efficiency 倒序排列
接著從頭開始走 i = 0, 1, 2, ... , n - 1
因為 efficiency 是從大到小排序，所以 i 走到的一定是之前沒到過的新低 efficiency
以他為最低的 efficiency，往前挑大的 k 個 speed (prioirty_queue 維護)
---
有沒有可能以這個數字當最低的 efficiency，但是挑的 k 個 speed 沒有對應到？
不可能，因為如果這樣的話，他可以往前選大一點的 efficiency!
---
speed 總和最大 -> priority_queue 去挑 k 個
efficiency 最小 -> 先 sorting 過後再弄
*/

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> es(n);
        for (int i = 0; i < n; i++)
            es[i] = {efficiency[i], speed[i]};
        
        // sort efficiency in descending order
        sort(es.rbegin(), es.rend());
        
        long speed_sum = 0, ans = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < n; i++) {
            int s = es[i].second;
            speed_sum += s;
            pq.push(s);
            if (pq.size() > k) {
                speed_sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, speed_sum * es[i].first); 
        }
        return ans % 1000000007;
    }
};
/*
Runtime: 192 ms, faster than 20.42% of C++ online submissions for Maximum Performance of a Team.
Memory Usage: 35.5 MB, less than 81.34% of C++ online submissions for Maximum Performance of a Team.
*/
