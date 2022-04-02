
// Biweekly Contest 75

/*
應該算是 DP
---
最後超時不到一分鐘 AC，雖然頁面顯示 Accepted ，但不納入計算 。。。
之前都是三題，就因為他，再次兩題，好不甘心 QQ 排名應該會掉
我討厭 DP
難得前兩題超快速做完的
---
這次 contest 的後兩題都是可以暴力解，題目 size 都是 10^5，亂搞會 TLE
---
這份 code 寫得好醜
---
哎，先睡了
*/

class Solution {
public:
    long long numberOfWays(string s) {
        vector<pair<char, int>> stats;
        stats.push_back(make_pair('0', 0));
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == stats.back().first)
                stats.back().second++;
            else
                stats.push_back(make_pair(s[i], 1));
        }
        
        if(stats.size() < 3)
            return 0;
        
        
        long long ans = 0;
        
        vector<pair<long long, long long>> c01(stats.size(), make_pair(0, 0));
        
        vector<long long> cc(stats.size(), 0);

        long long c0 = 0, c1 = 0;
        
        if (stats[stats.size() - 1].first == '0')
            c0 += stats[stats.size() - 1].second;
        if (stats[stats.size() - 1].first == '1')
            c1 += stats[stats.size() - 1].second;

        if (stats[stats.size() - 2].first == '0')
            c0 += stats[stats.size() - 2].second;
        if (stats[stats.size() - 2].first == '1')
            c1 += stats[stats.size() - 2].second;

        
        cc[stats.size() - 2] = (long long) stats[stats.size() - 2].second * stats[stats.size() - 1].second;
        
        
        for (int i = ((int)stats.size()) - 3; i >= 0; i--) {
            
            c01[i] = make_pair(c0, c1);
            
            if (i % 2 == 0)
                cc[i] = cc[i+2] + stats[i].second * c1;
            else
                cc[i] = cc[i+2] + stats[i].second * c0;
            
            // cout << "i = " << i << " " << cc[i] << endl;

            
            if (stats[i].first == '0')
                c0 += stats[i].second;
            if (stats[i].first == '1')
                c1 += stats[i].second;
            

        }   
        
        
        for(int i = 0; i < (int)stats.size() - 1; i++) {
            ans += stats[i].second * cc[i+1];
        }
        
        
        return ans;
    }
};
