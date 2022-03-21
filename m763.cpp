
// 2022.3.21

/*
我用 interval merging 的方式來寫這一題~
---
雖然有用到 sort 乍看之下是 O(n log n)，但因為固定都是 26 個東西在排，所以這邊也是常數！
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0; i < s.length(); i++) {
            if(first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        vector<pair<int, int>> ps;
        for(int i = 0; i < 26; i++) {
            if(first[i] != -1)
                ps.push_back({first[i], last[i]});
        }
        
        sort(ps.begin(), ps.end());
        
        pair<int, int> cur = *ps.begin();
        
        vector<int> ans;
        for(int i = 1; i < ps.size(); i++) {
            if(ps[i].first < cur.second) {
                cur.second = max(ps[i].second, cur.second);
            }
            else {
                ans.push_back(cur.second - cur.first + 1);
                cur = ps[i];
            }
        }
        ans.push_back(cur.second - cur.first + 1);
        return ans;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition Labels.
Memory Usage: 6.6 MB, less than 87.54% of C++ online submissions for Partition Labels.
*/
