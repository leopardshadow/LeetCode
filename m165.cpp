
// 2022.2.25

/*
一開始我 parsing 忘了加 while 迴圈結束後的那行，導致最後一個 revision 數字沒被抓出來..
把各自的 revision 數字抓出來後，剩下的事情就很簡單了，補零後比較數字大小
從左至右，有遇到誰比誰大就回傳，如果一直到最後都沒分出勝負，那就代表一樣，回傳 0
*/

class Solution {
    void parse(vector<int> &v, const string &version) {
        int start = 0, end = version.find(".");
        while(end != string::npos) {
            v.push_back(atoi(version.substr(start, end - start).c_str()));
            start = end + 1;
            end = version.find(".", start);
        }
        v.push_back(atoi(version.substr(start).c_str()));
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        parse(v1, version1);
        parse(v2, version2);
        vector<int> &v = (v1.size() < v2.size()) ? v1 : v2;
        int mx = max(v1.size(), v2.size());
        for(int i = v.size(); i < mx; i++)
            v.push_back(0);
        int i;
        for(i = 0; i < v1.size(); i++) {
            if(v1[i] < v2[i])
                return -1;
            else if(v1[i] > v2[i])
                return 1;
        }
        return 0;
    }
};

/*
Runtime: 7 ms, faster than 5.70% of C++ online submissions for Compare Version Numbers.
Memory Usage: 6.2 MB, less than 35.61% of C++ online submissions for Compare Version Numbers.
*/
