
// Weekly Contest 293

/*
偷懶寫法：anagram 懶得用 map 比較，加上 string 長度很短，直接 sort 後比較 XD
*/

class Solution {
    bool isAna(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            if (isAna(ans.back(), words[i]))
                continue;
            else
                ans.push_back(words[i]);
        }
        return ans;
    }
};
/*
Runtime: 12 ms, faster than 85.71% of C++ online submissions for Find Resultant Array After Removing Anagrams.
Memory Usage: 12.4 MB, less than 42.86% of C++ online submissions for Find Resultant Array After Removing Anagrams.
*/
