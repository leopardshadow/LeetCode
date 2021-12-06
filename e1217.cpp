// 2021.12.6

/*
題目好長，但其實就只是在算這個 vector 中有幾個偶數和奇數，
並回傳小的那個

*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCnt = 0, evenCnt = 0;
        for(int i = 0; i < position.size(); i++) {
            if(position[i] % 2 == 0)
                evenCnt++;
            else
                oddCnt++;
        }
        return min(evenCnt, oddCnt);
    }
};

/*
Runtime: 4 ms, faster than 49.74% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
Memory Usage: 7.4 MB, less than 10.09% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
*/
