
// Weekly Contest 295  

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int c1[26] = { 0 }, c2[26] = { 0 };
        for (char &c : s)
            c1[c - 'a']++;
        for (char &c : target)
            c2[c - 'a']++;
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
            if (c2[i])
                ans = min(ans, c1[i] / c2[i]);
        return ans;
    }
};
/*
Runtime: 5 ms, faster than 100.00% of C++ online submissions for Rearrange Characters to Make Target String.
Memory Usage: 6.1 MB, less than 66.67% of C++ online submissions for Rearrange Characters to Make Target String.
*/
