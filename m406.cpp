

// 2022.6.29

/*
換個想法，如果給解答，要怎麼驗證結果
[hx, kx], [hy, ky]
如果
 - hx < hy:  要往前找到大於等於 hy 然後 +1
 - hx >= hy: ky = kx + 1
然後就卡住了 ><
---
依據
1. height 高到低
2. 如果一樣的話，因為他是算前面大於等於的，所以 k 會是低到高
---
偷看討論區ㄉ
---
試試看 BIT, segment tree
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // sort people by 
        // 1. heights (higher -> lower)
        // 2. if same hieght, sort by k (lower->higher)
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> ans;
        for (auto &p : people){
            ans.insert(ans.begin() + p[1], p);
        }
        return ans;
    }
};
/*
Runtime: 193 ms, faster than 47.99% of C++ online submissions for Queue Reconstruction by Height.
Memory Usage: 12.1 MB, less than 63.86% of C++ online submissions for Queue Reconstruction by Height.
*/
