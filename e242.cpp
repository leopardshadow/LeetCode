/*
Alternative: use hash map
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

/*
Runtime: 16 ms, faster than 35.12% of C++ online submissions for Valid Anagram.
Memory Usage: 7.3 MB, less than 45.09% of C++ online submissions for Valid Anagram.
*/