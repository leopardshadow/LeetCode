
// 2022.8.25

/*
Easy~
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int c1[26] = { 0 }, c2[26] = { 0 };
        for (const char &c : ransomNote)
            c1[c - 'a']++;
        for (const char &c : magazine)
            c2[c - 'a']++;
        for (int i = 0; i < 26; i++)
            if (c1[i] > c2[i])
                return false;
        return true;
    }
};
/*
Runtime: 7 ms, faster than 98.98% of C++ online submissions for Ransom Note.
Memory Usage: 8.8 MB, less than 72.69% of C++ online submissions for Ransom Note.
*/
