// Greedy

/*
這題的關鍵在於 10 元只能用在找 20 元零錢的時候，當有人付 20 元時，其實我有兩種選擇
找給他 10 + 5 或是 5 + 5 + 5，但我們優先給他 10 + 5，如果 10 和 5 不夠，才用 3 個 5 找零
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0;
        for (int b : bills) {
            if (b == 5)
                cnt5++;
            if (b == 10) {
                cnt10++;
                cnt5--;
                if (cnt5 < 0)
                    return false;
            }
            if (b == 20) {
                // 10 + 5
                if (cnt10 && cnt5) {
                    cnt10--;
                    cnt5--;
                }
                // 5 + 5 + 5
                else {
                    cnt5 -= 3;
                }
                if (cnt5 < 0)
                    return false;
            }
        }
        return true;
    }
};
