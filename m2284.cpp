
// Biweekly Contest 79

/*
發現我的寫法有用到他的 hint：words 數量 = 空白數量 +1
*/

class Solution {
    int cnt(const string &s) {
        int ret = 1;
        for (const char &c : s)
            if (c == ' ')
                ret++;
        return ret;
    }
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> m;
        for (int i = 0; i < messages.size(); i++) {
            m[senders[i]] += cnt(messages[i]);
        }
        string ans;
        int maxCnt = -1;
        for (auto it : m) {
            if (it.second > maxCnt) {
                ans = it.first;
                maxCnt = it.second;
            }
            else if (it.second == maxCnt && it.first > ans)
                ans = it.first;
        }
        return ans;
    }
};
/*
Runtime: 317 ms, faster than 50.00% of C++ online submissions for Sender With Largest Word Count.
Memory Usage: 71.5 MB, less than 50.00% of C++ online submissions for Sender With Largest Word Count.
*/
