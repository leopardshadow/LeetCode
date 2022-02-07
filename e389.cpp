
// 2022.2.7 過年後第一天XD

class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26] = { 0 };
        for(const char &c : t)
            cnt[c - 'a']++;
        for(const char &c : s)
            cnt[c - 'a']--;
        for(int i = 0; i < 26; i++)
            if(cnt[i])
                return i + 'a';
        return 0;
    }
};

/*
Runtime: 8 ms, faster than 17.39% of C++ online submissions for Find the Difference.
Memory Usage: 6.6 MB, less than 67.00% of C++ online submissions for Find the Difference.
*/
