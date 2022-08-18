
// 2022.8.18

/*
第一眼看到還以為是 DP，但其實沒這麼麻煩
用 greedy + heap 就好
---
要讓挑的數字價值最大的話就是挑出現最多次的！
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (const int &n : arr)
            m[n]++;
        
        priority_queue<pair<int, int>> pq;
        for (auto &a : m)
            pq.push({a.second, a.first});
        
        int ans = 0, rmCnt = 0;
        while (pq.size() && rmCnt < arr.size() / 2) {
            rmCnt += pq.top().first;
            pq.pop();
            ans++;
        }
        return ans;
    }
};
/*Runtime: 370 ms, faster than 43.61% of C++ online submissions for Reduce Array Size to The Half.
Memory Usage: 81.1 MB, less than 29.25% of C++ online submissions for Reduce Array Size to The Half.
*/
