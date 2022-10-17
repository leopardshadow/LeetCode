
// 2022.10.17

/*
Easy~
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool s[26] = { 0 };
        for (const char &c : sentence)
            s[c - 'a'] = true;
        for (int i = 0; i < 26; i++)
            if (!s[i])
                return false;
        return true;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if the Sentence Is Pangram.
Memory Usage: 6.3 MB, less than 98.63% of C++ online submissions for Check if the Sentence Is Pangram.
*/
