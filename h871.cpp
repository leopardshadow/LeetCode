
// 2022.8.20
// Switch Day :D

/*
自己寫出來的 Hard 耶，果然只要不是 DP 就有機會嗎XDD
概念是既然要停最少次，那就選有最多油的加油站加 (greedy + heap)
但是開一開不一定還會有油
綜合兩點：
先把加油站位置排序，有油就繼續開，沒有油就回頭去看之前由最多的
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // priority_queue<pair<int, int>> pq;
        sort(stations.begin(), stations.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        stations.insert(stations.end(), {target, 0});
        
        priority_queue<int> pq;
        
        int pos = 0, fuel = startFuel, ans = 0;  
        for (auto &s : stations) {
            
            // can it reach s[0] (nextPos)
            int nextPos = s[0];
            fuel -= (nextPos - pos);
            while (fuel < 0) {
                if (pq.empty())
                    return -1;
                else {
                    fuel += pq.top();
                    pq.pop();
                    ans++;
                }
            }
            pos = nextPos;
            
            // can refuel here later
            pq.push(s[1]);
        }
            
        return ans;
    }
};
/*
Runtime: 28 ms, faster than 93.50% of C++ online submissions for Minimum Number of Refueling Stops.
Memory Usage: 16.3 MB, less than 51.25% of C++ online submissions for Minimum Number of Refueling Stops.
*/
