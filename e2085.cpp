// Biweekly Contest 66

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> m1, m2;
        for(string w : words1)
            m1[w]++;
        for(string w : words2)
            m2[w]++;
        int ans = 0;
        for(auto it = m1.begin(); it != m1.end(); it++) {
            if(it->second == 1 && m2[it->first] == 1)
                ans++;
        }
        return ans;
    }
};

/*
Runtime: 50 ms, faster than 85.71% of C++ online submissions for Count Common Words With One Occurrence.
Memory Usage: 19.9 MB, less than 64.29% of C++ online submissions for Count Common Words With One Occurrence.
*/
