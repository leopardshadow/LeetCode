
// 2022.4.10

/*
就照著他說的做
題目說 C, D, + 一定會可以做，不會數字不夠，所以也不用任何條件檢查，但面試時要想到可能會有問題
---
查了一下從 vector 中拿到倒數第二個元素有沒有什麼有趣的寫法和 C++ 中 accumulate (Haskell 的話可以用 sum) 的寫法
---
話說寫這題的時候，讚 / 倒讚是 1035 / 1379
*/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for (const string &op : ops) {
            if (op == "+")
                scores.push_back(scores.end()[-1] + scores.end()[-2]);
            else if (op == "D")
                scores.push_back(scores.back() * 2);
            else if (op == "C")
                scores.pop_back();
            else
                scores.push_back(atoi(op.c_str()));
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
/*
Runtime: 4 ms, faster than 71.34% of C++ online submissions for Baseball Game.
Memory Usage: 8.3 MB, less than 69.92% of C++ online submissions for Baseball Game.
*/
