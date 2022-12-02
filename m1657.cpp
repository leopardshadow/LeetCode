
// 2022.12.2

/*
第一條規則是可以不限次數亂換順序，所以我們可以讓他排成指定的樣子，因此各字元順序不重要，只要各自出現的次數
第二條規則可以讓 character 互相交換，所以重要的是出現的次數，哪個數字是誰的不重要
---
要注意第二條規則中，只能和有出現過的交換，所以要特別檢查
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int cnt1[26] = { 0 }, cnt2[26] = { 0 };
        if (word1.length() != word2.length())
            return false;
        for (int i = 0; i < word1.length(); i++) {
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }
        // components should be the same
        for (int i = 0; i < 26; i++) {
            if ((cnt1[i] > 0 && cnt2[i] == 0) || 
                (cnt1[i] > 0 && cnt2[i] == 0))
                return false;
        }
        sort(begin(cnt1), end(cnt1));
        sort(begin(cnt2), end(cnt2));
        for (int i = 0; i < 26; i++)
            if (cnt1[i] != cnt2[i])
                return false;
        return true;
    }
};
/*
Runtime: 184 ms, faster than 67.07% of C++ online submissions for Determine if Two Strings Are Close.
Memory Usage: 20.2 MB, less than 94.61% of C++ online submissions for Determine if Two Strings Are Close.
*/
