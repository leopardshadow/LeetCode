/*
s = s0 s1 s2 s3 s4 ...

if it ends with si, how long the substring can be
(F denotes -1 here)

    0 1 2 3 4 5 6 7
s = a b c a b c b b
   (F F F 0 1 2 4 6)
 
    0 1 2 3
s = b b b b
    F 0 1 2
    
    0 1 2 3 4 5
s = p w w k e w
    F F 1 3 4 2
*/

/*
sliding window + DP
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char, int> m;
        for(int l = 0, r = 0; l < s.length(); l++) {
            if(m.find(s[l]) != m.end())
                r = max(r, m[s[l]] + 1);
            ans = max(ans, l - r + 1);
            m[s[l]] = l;
        }
        return ans;
    }
};

//***************************************************************************//
// Review: 2021.11.28 before G VO

// sliding window
/* 
嘗試用 bitmap 的寫法
沒注意到除了英文字之外，還包括空白、數字和特殊符號 @@
但概念大致上是對的
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned int num = 0;
        int l = 0, r = 0;
        int maxLen = 0;
        while(r < s.length()) {
            if(!(num & (1 << (s[r] - 'a')))) {
                num |= (1 << (s[r] - 'a'));
            }
            else{
                while(l < s.length() && s[l] != s[r]) {
                    num &= ~(1 << (s[l] - 'a'));
                    l++;
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
