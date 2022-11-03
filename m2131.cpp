
// 2022.11.3

/*
這題有一個很大的限制：words 的長度都是 2，如果不是的話很麻煩
因為長度都是 2，所以都是對好的，不會出現砍在中間 (12)(34321)
---
這題滿有趣的，雖然我有看了解答 ><
*/

class Solution {
    int min(int x, int y) {
        if (x < y)
            return x;
        return y;
    }
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> wc;  // word counts
        for (const string &w : words)
            wc[w]++;
        
        int ans = 0;
        bool central = false;
        
        for (const auto& [word, cnt] : wc) {
            if (word[0] == word[1]) {
                if (cnt % 2 == 0)
                    ans += cnt;
                else {
                    ans += (cnt - 1);  // 只會有一個是中心，e.g. (aa)(b|b)(aa)
                    central = true;
                }
            }
            else if (word[0] < word[1] && wc.count({word[1], word[0]})) {  // avoid duplicates
                ans += 2 * min(cnt, wc[{word[1], word[0]}]);  // word length = 2
            }
        }
        if (central) // 如果有中心的話，因為之前先扣掉了，要加回來
            ans++;
        return 2 * ans;
    }
};
/*
Runtime: 631 ms, faster than 72.00% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.
Memory Usage: 167.9 MB, less than 60.00% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.
*/
