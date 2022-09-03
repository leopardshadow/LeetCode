
// 2022.9.3

/*
backtrack~
*/

class Solution {
    vector<int> ans;
    int k, n;
    void backtrack(int size, int num) {
        if (size == n) {
            ans.push_back(num);
            return;
        }
        for (int i = 0; i < 10; i++) {
            int last = num % 10;
            if (i == last + k || i == last - k) {
                backtrack(size + 1, 10 * num + i);
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        this->n = n;
        this->k = k;
        for (int i = 1; i < 10; i++)
            backtrack(1, i);
        return ans;
    }
};
/*
Runtime: 3 ms, faster than 74.35% of C++ online submissions for Numbers With Same Consecutive Differences.
Memory Usage: 7.8 MB, less than 68.28% of C++ online submissions for Numbers With Same Consecutive Differences.
*/
