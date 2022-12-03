
// 2022.12.3

/*
把出現的次數排序後組成字串
*/

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (const char &c : s)
            m[c]++;
        vector<pair<int, char>> v;
        for (const auto &x : m)
            v.push_back({x.second, x.first});
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string ans = "";
        for (const auto &p : v)
            for (int i = 0; i < p.first; i++)
                ans += p.second;
        return ans;
    }
};
/*
Runtime: 17 ms, faster than 76.68% of C++ online submissions for Sort Characters By Frequency.
Memory Usage: 8.4 MB, less than 67.07% of C++ online submissions for Sort Characters By Frequency.
*/
