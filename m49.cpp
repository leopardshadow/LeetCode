class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > m;
        vector<vector<string> > ans;
        string ss;
        for(const auto s : strs) {
            ss = s;
            sort(ss.begin(), ss.end());
            m[ss].push_back(s);
        }
        for(map<string, vector<string> >::iterator it = m.begin(); it != m.end(); it++) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};

/*
Runtime: 36 ms, faster than 72.98% of C++ online submissions for Group Anagrams.
Memory Usage: 19.8 MB, less than 65.92% of C++ online submissions for Group Anagrams.
*/