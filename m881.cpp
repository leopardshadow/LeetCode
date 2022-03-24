
// 2022.3.24

/*
一開始把題目想得太複雜了，還想用 map 的 tree 性質，或用 lower_bound
但其實不用這麼麻煩
---
Notes.
想用 m.erase(m.rbegin()) 結果發現不行，iterator 和 reverse_iterator 是不同東西
map 的話可以從 end --> begin，iterator 用減的
---
2-pointer 的解很漂亮，偷看 tag 發現有 2-pointer
最重的和最輕的搭，如果超過 limit，就表示那個重的只能自己一組 ; 如果在 limit 之內，那就把兩個湊一起
頭、尾指標移動
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        while(i <= j) {
            if(people[i] + people[j] > limit)
                j--;
            else {
                j--;
                i++;
            }
            ans++;
        }
        return ans;
    }
};
/*
Runtime: 97 ms, faster than 68.94% of C++ online submissions for Boats to Save People.
Memory Usage: 41.9 MB, less than 91.53% of C++ online submissions for Boats to Save People.
*/
