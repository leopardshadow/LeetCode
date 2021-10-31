

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> m;
        for(int n : nums) {
            m[n] = true;
        }
        int maxLen = 0, i, len;
        map<int, bool>::iterator f;
        while(!m.empty()) {
            auto ms = m.begin();
            i = 1;
            while((f = m.find(ms->first+i)) != m.end()) {
                i++;
                m.erase(f);
            }
            len = i - 1; // note the range
            i = 1;
            while((f = m.find(ms->first-i)) != m.end()) {
                i++;
                m.erase(f);
            }
            len += i;
            maxLen = max(len, maxLen);
            m.erase(ms);
        }
        return maxLen;
    }
};

/*
Runtime: 96 ms, faster than 64.07% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 31.7 MB, less than 29.53% of C++ online submissions for Longest Consecutive Sequence.
*/