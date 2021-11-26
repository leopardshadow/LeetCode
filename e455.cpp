// greedy

/*
把小餅乾分給小食量ㄉ
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] < g[i])
                j++;
            else {
                i++;
                j++;
                ans++;
            }
        }
        return ans;
    }
};

/*
Runtime: 53 ms, faster than 11.96% of C++ online submissions for Assign Cookies.
Memory Usage: 17.4 MB, less than 76.85% of C++ online submissions for Assign Cookies.
*/
