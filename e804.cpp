
// 2022.8.17

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> s2m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set <string> m;
        
        for (const string &w : words) {
            string code = "";
            for (const char &c : w) {
                code += s2m[c - 'a'];
            }
            m.insert(code);
        }
        
        return m.size();
    }
};
/*
Runtime: 4 ms, faster than 71.25% of C++ online submissions for Unique Morse Code Words.
Memory Usage: 8.6 MB, less than 30.73% of C++ online submissions for Unique Morse Code Words.
*/
