
// Weekly Contest 298
// 2022.6.19

/*
就 ... 跑過一次w
*/

class Solution {
public:
    string greatestLetter(string s) {
        set<char> ss;
        for (char c : s)
            ss.insert(c);
        for (int i = 25; i >= 0; i--) {
            char a = 'a' + i, A = 'A' + i;
            if (ss.count(a) && ss.count(A))
                return string(1, A);
        }
        return "";
    }
};
/*
Runtime: 10 ms, faster than 20.00% of C++ online submissions for Greatest English Letter in Upper and Lower Case.
Memory Usage: 6.9 MB, less than 60.00% of C++ online submissions for Greatest English Letter in Upper and Lower Case.
*/
