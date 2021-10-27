class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        vector<vector<string> > ans;
        string ss;
        for(const auto s : strs) {
            ss = s;
            sort(ss.begin(), ss.end());
            m[ss].push_back(s);
        }
        for(const auto mm : m) {
            ans.push_back(mm.second);
        }
        
        return ans;
    }
};

// Use map
/*
Runtime: 36 ms, faster than 72.98% of C++ online submissions for Group Anagrams.
Memory Usage: 19.8 MB, less than 65.92% of C++ online submissions for Group Anagrams.
*/

// Use unordered_map
/*
Runtime: 28 ms, faster than 93.71% of C++ online submissions for Group Anagrams.
Memory Usage: 20.7 MB, less than 48.27% of C++ online submissions for Group Anagrams.
*/