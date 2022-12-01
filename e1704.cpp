
// 2022.12.1

/*
Easy
*/

class Solution {
    bool isVowel(const char &c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            if (isVowel(s[i]))
                cnt++;
        }
        for (int i = s.length() / 2; i < s.length(); i++) {
            if (isVowel(s[i]))
                cnt--;
        }
        return cnt == 0;
    }
};
/*
Runtime: 2 ms, faster than 89.18% of C++ online submissions for Determine if String Halves Are Alike.
Memory Usage: 6.7 MB, less than 56.35% of C++ online submissions for Determine if String Halves Are Alike.
*/
