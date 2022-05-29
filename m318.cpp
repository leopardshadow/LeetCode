
// 2022.5.29

/*
我用 integer 的後 26 位來表示 a-z 有沒有出現過
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> xs;
        for (const string &w : words) {
            int x = 0;
            for (const char &c : w)
                x |= 1 << (c - 'a');
            xs.push_back(x);
        }
        size_t ans = 0;
        for (int i = 0; i < xs.size(); i++) {
            for (int j = i + 1; j < xs.size(); j++) {
                if (! (xs[i] & xs[j]))
                    ans = max(ans, words[i].length() * words[j].length());
            }
        }
        return ans;
    }
};
/*
Runtime: 40 ms, faster than 96.02% of C++ online submissions for Maximum Product of Word Lengths.
Memory Usage: 15.9 MB, less than 55.91% of C++ online submissions for Maximum Product of Word Lengths.
*/
