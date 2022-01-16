
// 2022.1.16

/*
我把他分三種 case 來考慮
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev = -1, ans = 1;
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 1) {
                if(prev != -1)
                    ans = max(ans, (i - prev) / 2 );  // .. X ..
                else
                    ans = max(ans, i);  // X ...
                prev = i;
            }
        }
        ans = max(ans, (int)seats.size() - prev - 1);  // ... X
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 96.68% of C++ online submissions for Maximize Distance to Closest Person.
Memory Usage: 17 MB, less than 93.10% of C++ online submissions for Maximize Distance to Closest Person.
*/
