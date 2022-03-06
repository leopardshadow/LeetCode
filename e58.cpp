
/*
今天是 2022.3.6
看到 299 就多寫一題湊個 300 XDD
---
easy 但還吃 WA，一開始 && 前後寫反...
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while(i >= 0 && s[i] == ' ')
            i--;
        int j = i;
        while(j >= 0 && s[j] != ' ')
            j--;
        return i - j;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
Memory Usage: 6.6 MB, less than 52.32% of C++ online submissions for Length of Last Word.
*/
