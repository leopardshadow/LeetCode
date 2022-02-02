
// 2022.2.2 農曆初二

/*
看起來就是 sliding window 的樣子
寫完後跑 Run Code 接著 Submit，連 typo 都沒有 XD
sth. :( today
*/

class Solution {
    int cnt[26], ana[26];
    bool isAnagram() {
        for(int i = 0; i < 26; i++)
            if(cnt[i] != ana[i])
                return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size())
            return {};
        for(int i = 0; i < p.size(); i++)
            ana[p[i] - 'a']++;
        for(int i = 0; i < p.size(); i++)
            cnt[s[i] - 'a']++;
        if(isAnagram())
            ans.push_back(0);
        for(int i = p.size(); i < s.size(); i++) {
            cnt[s[i - p.size()] - 'a']--;
            cnt[s[i] - 'a']++;
            if(isAnagram())
                ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};

/*
Runtime: 7 ms, faster than 97.78% of C++ online submissions for Find All Anagrams in a String.
Memory Usage: 8.6 MB, less than 90.96% of C++ online submissions for Find All Anagrams in a String.
*/
