

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(int n : nums) {
            m[n] = true;
        }
        int maxLen = 0, i, len;
        unordered_map<int, bool>::iterator f;
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
Runtime: 68 ms, faster than 80.84% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 30.9 MB, less than 48.16% of C++ online submissions for Longest Consecutive Sequence.
*/




// 2022.7.5

/*
偷懶，意外的很快w
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = 1, curLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] + 1 == nums[i])
                ans = max(ans, ++curLen);
            else if (nums[i-1] == nums[i])
                ;
            else
                curLen = 1;
        }
        return ans;
    }
};
/*
Runtime: 101 ms, faster than 89.18% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 33.8 MB, less than 85.63% of C++ online submissions for Longest Consecutive Sequence.
*/
