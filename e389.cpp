
// 2022.2.7 過年後第一天XD

/*
這題超多種做法的，我一開始是用 map 計算各個字母出現的數量
---
也可以計算兩個字串總和的差
---
還有 xor!! 100% faster
---
還有其他作法，像是 sort 後同時去指，但比較慢，寫起來也比較複雜w
*/

// 我一開始的想法，用 map
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


// xor !
/*
用 xor 誰長誰短不重要
*/
// xor !ㄕ

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



// 參考 https://leetcode.com/problems/find-the-difference/discuss/1752248/C%2B%2B-or-6-approach-from-view-of-sort-count-xor-and-sum
/* 
在 C++， -5 % 2 = -1，所以用加/減的話可能會出現負數
這篇他是直接取 char 變成正的
如果把它 +256 後再 mod 意思一樣
-1 -> 255
-2 -> 254
-3 -> 253
...
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for (auto &c: t) (sum+=c)%=256;
        for (auto &c: s) (sum-=c)%=256;
        return (sum + 256) % 256;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Difference.
Memory Usage: 6.7 MB, less than 25.35% of C++ online submissions for Find the Difference.
*/
