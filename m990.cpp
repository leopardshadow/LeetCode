
// 2022.9.26
// 倒數一週了！

/*
看到 SAT 的問題很自然就把 a, b, c 這些變數的值固定在 true/false，但他其實根本沒這樣說，只要是 integer 都可以被 assign...
---
原本想說 problem size 很小可以用 BFS 就好，但好麻煩，寫不出 bug free QQ
還是（別人寫的） union find 比較漂亮 
*/

class Solution {
    int uf[26] = { 0 };
    int find(int x) {
        if (x != uf[x]) 
            uf[x] = find(uf[x]);
        return uf[x];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++)
            uf[i] = i;
        for (string &e : equations) {
            if (e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a');
        }
        for (string &e : equations) {
            if (e[1] == '!' && (find(e[0] - 'a') == find(e[3] - 'a')))
                return false;
        }
        return true;
    }
};
/*
Runtime: 18 ms, faster than 19.12% of C++ online submissions for Satisfiability of Equality Equations.
Memory Usage: 11.4 MB, less than 70.01% of C++ online submissions for Satisfiability of Equality Equations.
*/
