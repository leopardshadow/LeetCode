
// 2022.1.6

/*
有點意外這樣的寫法沒有 TLE XD
---
因為只有一台車，所以 n 個人從 from 到 to，他們在 [from, to) 都會佔著車上 n 個位置
所以只要把所有 location 車上會有的人都加上去，看會不會超過 capacity 就好
---
一個小細節注意，從 from 到 to 是 [from, to)，因為到了 to 就下車了，在 to 上車的人可以坐在 to 下車的人的座位
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int pass[1000] = { 0 };
        
        for(auto trip : trips) {
            for(int i = trip[1]; i < trip[2]; i++) {
                pass[i] += trip[0];
            }
        }
        for(int i = 0; i < 1000; i++) {
            if(pass[i] > capacity)
                return false;
        }
        return true;
    }
};

/*
Runtime: 49 ms, faster than 5.86% of C++ online submissions for Car Pooling.
Memory Usage: 10.1 MB, less than 60.37% of C++ online submissions for Car Pooling.
*/
