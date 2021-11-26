// backtracking
// exhaustive search every possibilities

/*
注意範圍，包括：
加了 "." 要扣掉
substr 要是超過了剩下的長度，再扣時會出現問題，所以要先檢查
("01".substr(0, 3)，但我們之後又往前扣惹，他說明明就沒給我的東西還要我付)
*/

class Solution {
    string ip;
    vector<string> ans;
public:
    // n =   0.  1. 2.3. 
    //      192.168.1.1
    void solve(string &s, int n, int start) {
        if (n == 4) {
            if (start == s.length())
                ans.push_back(ip.substr(0, ip.length() - 1));
            return;
        }
        if (start >= s.length())
            return;
        
        int len = 1;
        if (start + len <= s.length() && stoi(s.substr(start, len)) <= 255) {
            ip += s.substr(start, len) + ".";
            solve(s, n+1, start+len);
            ip = ip.substr(0, ip.length() - len - 1);
        }

        for (len = 2; len <= 3; len++) {
            if (start + len <= s.length() && s[start] != '0' && stoi(s.substr(start, len)) <= 255) {
                ip += s.substr(start, len) + ".";
                solve(s, n+1, start+len);
                ip = ip.substr(0, ip.length() - len - 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0);
        return ans;
    }
};

/*
Runtime: 3 ms, faster than 66.39% of C++ online submissions for Restore IP Addresses.
Memory Usage: 6.6 MB, less than 83.85% of C++ online submissions for Restore IP Addresses.
*/
