
// 2022.10.19

/*
專心看他的規則RRRRR
*/

struct cmp {
    bool operator()(pair<int, string> a, pair<int, string> b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (const string &w : words)
            m[w]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto a : m)
            pq.push({a.second, a.first});
        vector<string> ans;
        int times = INT_MAX, prev = 0;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            if (times != pq.top().first) {
                times = pq.top().first;
                sort(ans.begin() + prev, ans.begin() + i);
                prev = i;
            }
            sort(ans.begin() + prev, ans.end());
            pq.pop();
        }
        return ans;
    }
};

/*
Runtime: 32 ms, faster than 27.39% of C++ online submissions for Top K Frequent Words.
Memory Usage: 12.8 MB, less than 39.56% of C++ online submissions for Top K Frequent Words.
*/
