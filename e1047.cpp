
// 2022.11.10

/*
stack!
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for (const char &c : s) {
            if (ans.length() && c == ans.back())
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};
/*
Runtime: 8 ms, faster than 99.68% of C++ online submissions for Remove All Adjacent Duplicates In String.
Memory Usage: 10.9 MB, less than 74.37% of C++ online submissions for Remove All Adjacent Duplicates In String.
*/
