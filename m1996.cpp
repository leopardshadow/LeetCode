
// 2022.9.9

/*
偷看了 Hint，但最後不算有用到
---
想法 greedy
先依照 atk 倒序排序，atk 大的在前
這時候可以知道就 atk 方面，後面的角色比較可能是 weak
因為他 atk 會輸，只要比 def 就好了
---
如果 atk 一樣，要順序排列，def 小的在前，才不會多數
例如
[10, 4]  [10, 3] 這個會多數一個
vs.
[10, 3]  [10, 4] 這個才是正確的
---
寫完後看 Topics，原來是 monotonic stack!
*/

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int> &a, vector<int> &b){
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        int cnt = 0, maxAtk = properties[0][0], maxDef = properties[0][1];
        for (int i = 1; i < properties.size(); i++) {
            vector<int> &c = properties[i];
            if (maxDef > c[1])
                cnt++;
            maxDef = max(maxDef, c[1]);
        }
        return cnt;
    }
};
/*
Runtime: 815 ms, faster than 78.18% of C++ online submissions for The Number of Weak Characters in the Game.
Memory Usage: 125.2 MB, less than 70.41% of C++ online submissions for The Number of Weak Characters in the Game.
*/
