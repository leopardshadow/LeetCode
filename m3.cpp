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