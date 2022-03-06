
// 2022.3.6
// Biweekly Contest 73

/*
吃了 2 次 WA
一次因為沒看清楚題目w，一次因為 while(n) 那邊 0 的問題
---
其實 STL 的 sort 沒有保證 stable，應該要用 stable_sort，但莫名其妙就過了
---
YC 提供的作法：像這種 mapping 很適合先把數字轉成字串來做，最後再轉回數字
先 to_string，接著 for 迴圈跑一次，最後 stoi，Done!
*/

class Solution {
    int tr(vector<int>& mapping, int n) {
        int m = 0;
        vector<int> ns;
        while(n) {
            ns.push_back(n % 10);
            n /= 10;
        }
        if(ns.size() == 0)  // due to while(n) { ...
            ns.push_back(0);
        for(int i = ns.size() - 1; i >= 0; i--) 
            m = 10 * m + mapping[ ns[i] ];
        return m;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int, int>> ps;
        for(const int &n : nums)
            ps.push_back({tr(mapping, n), n});
        
        sort(ps.begin(), ps.end(), [](pair<int, int> &p1, pair<int, int> &p2){
            return p1.first < p2.first;
        });
        
        vector<int> ans;
        for(const auto &p : ps)
            ans.push_back(p.second);
        return ans;
    }
};
