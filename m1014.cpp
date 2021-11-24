// DP D7

/*
自己想ㄉ
Key: 
   v[i] + v[j] + i - j
 = (v[i] + i) + (v[j] - j)
 
 把 +i / -j 的變動做在 value 裡
   
這個做法 time complexity 是 O(n) 但 space complexity 也是 O(n)，討論區有看到 SC O(1) 的做法
想法大致差不多，但我在迴圈是先建好 j 的表 (所以要 SC O(n)) ; 而他的作法則是反過來，建 i 的表去跑 j，但其實 i, j 是同向的，所以不用另外花空間去存!!
時間也會比較快，因為只走過一遍 vector，而我的作法走了兩次，空間還用比較多

我直觀上真的會用 (i < j) (v[i] + i) + max{j} (v[j] - j) 跑過全部 i 去想，有時候反著想比較快!!
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        vector<int> v_j(values.size(), 0);
        v_j.back() = values.back() - values.size() + 1;
        for(int i = v_j.size() - 2; i >= 1; i--)
            v_j[i] = max(values[i] - i, v_j[i+1]);
        for(int i = 0; i < values.size() - 1; i++)
            ans = max(ans, values[i] + i + v_j[i+1]);
        return ans;
    }
};

/*
Runtime: 73 ms, faster than 22.14% of C++ online submissions for Best Sightseeing Pair.
Memory Usage: 41 MB, less than 13.37% of C++ online submissions for Best Sightseeing Pair.
*/

//***************************************************************************//

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxI = values[0] + 0, ans = 0;
        for(int j = 1; j < values.size(); j++) {
            ans = max(ans, maxI + values[j] - j);
            maxI = max(maxI, values[j] + j);
        }
        return ans;
    }
};

/*
Runtime: 48 ms, faster than 76.02% of C++ online submissions for Best Sightseeing Pair.
Memory Usage: 39.2 MB, less than 98.91% of C++ online submissions for Best Sightseeing Pair.
*/
