class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26] = {0};
        for(int i = 0; i < s.length(); i++)
            cnt[s[i] - 'a'] += 1;
        for(int i = 0; i < s.length(); i++) {
            if(cnt[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

/*
Runtime: 20 ms, faster than 95.88% of C++ online submissions for First Unique Character in a String.
Memory Usage: 10.6 MB, less than 89.98% of C++ online submissions for First Unique Character in a String.
*/

// 2022.8.16
