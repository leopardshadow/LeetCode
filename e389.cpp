
// 2022.2.7 過年後第一天XD

/*
這題超多種做法的，我一開始是用 map 計算各個字母出現的數量
---
也可以計算兩個字串總和的差
---
還有 xor!! 100% faster
*/

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



class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(const char &c : t)
            ans ^= c;
        for(const char &c : s)
            ans ^= c;
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Difference.
Memory Usage: 6.7 MB, less than 67.00% of C++ online submissions for Find the Difference.
*/
