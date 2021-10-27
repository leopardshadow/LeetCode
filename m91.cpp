
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