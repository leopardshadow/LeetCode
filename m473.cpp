
// 2022.7.12

/*
今天卡住因為重複宣告了 n QQ
n = ... 要設的是 data member
結果前面不小心加了 int 
*/

class Solution {
    int n, quad, take;
    bool backtrack(vector<int>& matchsticks, int side, int bit, int sum) {
        if (side == 4)  // no need to check take, since quad = sum / 4
            return true;
        else {
            if (sum == quad)
                return backtrack(matchsticks, side + 1, 0, 0);
            for (int i = bit; i < n; i++) {
                if ((take & (1 << i)) || sum + matchsticks[i] > quad)
                    continue;
                take |= (1 << i);
                if (backtrack(matchsticks, side, i + 1, sum + matchsticks[i]))
                    return true;
                take ^= (1 << i);
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        n = matchsticks.size();
        take = 0;
        for (const int &m : matchsticks)
            sum += m;
        if (sum % 4 != 0 || matchsticks.size() < 4)
            return false;
        quad = sum / 4;
        return backtrack(matchsticks, 0, 0, 0);
    }
};
