
// 2022.5.10

/*
看來這週主題是 backtracking 了
---
Each number is used at most once.
所以所有的數字必須 unique，用順序的去選（e.g. 小到大）就可以避掉重複ㄉ
*/

class Solution {
    //
    vector<int> ns;
    vector<vector<int>> ans;
    
    //
    void backtrack(int num, int k, int sum) {
        if (sum == 0 && k == 0)
            ans.push_back(ns);
        else if (sum < 0 || k < 0)
            return;
        else {
            for (int i = num + 1; i <= 9; i++) {
                ns.push_back(i);
                backtrack(i, k - 1, sum - i);
                ns.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(0, k, n);
        return ans;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum III.
Memory Usage: 6.4 MB, less than 58.80% of C++ online submissions for Combination Sum III.
*/
