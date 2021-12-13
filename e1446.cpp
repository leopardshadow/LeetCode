class Solution {
public:
    int maxPower(string s) {
        int ans = 1, curLen = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i-1] == s[i]) {
                curLen++;
                ans = max(ans, curLen);
            }
            else {
                curLen = 1;
            }
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 70.90% of C++ online submissions for Consecutive Characters.
Memory Usage: 6.8 MB, less than 72.13% of C++ online submissions for Consecutive Characters.
*/
