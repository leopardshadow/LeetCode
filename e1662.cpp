
// 2022.10.25

/*
2-pointer~
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int ai = 0, aj = 0, bi = 0, bj = 0;
        while (ai < word1.size() && bi < word2.size()) {
            if (word1[ai][aj] != word2[bi][bj])
                return false;
            aj++; 
            bj++;
            if (aj == word1[ai].size()) {
                ai++;
                aj = 0;
            }
            if (bj == word2[bi].size()) {
                bi++;
                bj = 0;
            }
        }
        return ai == word1.size() && bi == word2.size();
    }
};
/*
Runtime: 4 ms, faster than 83.89% of C++ online submissions for Check If Two String Arrays are Equivalent.
Memory Usage: 11.3 MB, less than 97.08% of C++ online submissions for Check If Two String Arrays are Equivalent.
*/
