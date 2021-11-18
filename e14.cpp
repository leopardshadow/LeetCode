/*
一開始居然卡在雙層迴圈內部 break 只能跳一層...
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int len = 0;
        for( ; len < prefix.length(); len++) {
            for(int i = 1; i < strs.size(); i++) {
                if(strs[i].length() < len || strs[i][len] != prefix[len])
                    return prefix.substr(0, len);
            }
        }
        return prefix;
    }
};

/*
Runtime: 4 ms, faster than 71.82% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9 MB, less than 99.69% of C++ online submissions for Longest Common Prefix.
*/
