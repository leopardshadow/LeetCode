// Biweekly Contest 66

/*
這題感覺演算法的部分還好欸，主要就是看懂題目，然後照著寫
(自己講wwwww) 這邊 dr, dc 的寫法我覺得不錯
*/

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int robotR = startPos[0], robotC = startPos[1];
        int homeR = homePos[0], homeC = homePos[1];
        int dr = 1, dc = 1;
        if(robotR > homeR)
            dr = -1;
        if(robotC > homeC)
            dc = -1;
        int totalCost = 0;
        while(robotR != homeR) {
            robotR += dr;
            totalCost += rowCosts[robotR];
        }
        while(robotC != homeC) {
            robotC += dc;
            totalCost += colCosts[robotC];
        }
        return totalCost;
    }
};

/*
Runtime: 255 ms, faster than 50.00% of C++ online submissions for Minimum Cost Homecoming of a Robot in a Grid.
Memory Usage: 149.9 MB, less than 25.00% of C++ online submissions for Minimum Cost Homecoming of a Robot in a Grid.
*/
