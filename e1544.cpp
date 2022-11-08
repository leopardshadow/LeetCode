
// 2022.11.8

/*
Stack
*/

class Solution {
    bool bad(const char &a, const char &b) {
        if (abs(a - b) == 'a' - 'A')
            return true;
        else
            return false;
    }
public:
    string makeGood(string s) {
        deque<char> dq;
        for (const char &c : s) {
            if (!dq.empty() && bad(dq.back(), c))
                dq.pop_back();
            else
                dq.push_back(c);
        }
        string ans = "";
        for (int i = 0; i < dq.size(); i++)
            ans += dq[i];
        return ans;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Make The String Great.
Memory Usage: 6.6 MB, less than 43.30% of C++ online submissions for Make The String Great.
*/
