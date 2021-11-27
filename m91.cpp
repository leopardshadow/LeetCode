/*
原來我之前是用 map 喔 XDD
下面那個寫法應該比較直覺~~
*/


/*
s0 s1 s2 s3 s4
-----------------
(s0) - (s1 s2 s3 s4)
(s0 s1) - (s2 s3 s4)
*/
class Solution {
public:
    
    // use the hash to tackle TLE
    unordered_map<string, int> m;
    
    bool isN(string s) {
        return s[0] != '0' && stoi(s) >= 1 && stoi(s) <= 26;
    }
    
    int numDecodings(string s) {

        int sum = 0;
        if(s.length() == 0) {
            return 1;
        }
        if(m.find(s) != m.end()) {
            return m[s];
        }
        if(isN(s.substr(0, 1)))
            sum += numDecodings(s.substr(1));
        if(s.length() >= 2 && isN(s.substr(0, 2)))
            sum += numDecodings(s.substr(2));

        m[s] = sum;
        return sum;
    }
};

/*
Runtime: 4 ms, faster than 31.70% of C++ online submissions for Decode Ways.
Memory Usage: 8.1 MB, less than 8.11% of C++ online submissions for Decode Ways.
*/

//***************************************************************************//
// DP D10
/*
table[i] stroes the number of possible ways of splitting for the string s[0:i]

table[i] = table[i-1] (if string[i] is valid, otherwise: 0) +
           table[i-2] (if string.substr(i-1, 2) is valid, otherwise: 0)

*/

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        if (s.length() == 1)
            return 1;
        vector<int> table(s.length());
        table[0] = 1;
        table[1] = (s[1] == '0' ? 0 : table[0]) + (stoi(s.substr(0, 2)) <= 26 ? 1 : 0);
        for (int i = 2; i < s.length(); i++) {
            table[i] = (s[i] == '0' ? 0 : table[i-1]) + 
                        (stoi(s.substr(i-1, 2)) <= 26 && s[i-1] != '0' ? table[i-2] : 0);
        }
        return table.back();
    }
};

/*
Runtime: 7 ms, faster than 11.67% of C++ online submissions for Decode Ways.
Memory Usage: 6.1 MB, less than 91.18% of C++ online submissions for Decode Ways.
*/
