
// Weekly Contest 285 (2022.3.20)

/*
這題其實可以轉成 0/1 背包問題，因為 b_k 只要大於 a_k 就可以全拿分數 k，用 greedy 來想，b_k 只要恰恰比 a_k 多一就好
所以 numArrows 其實是背包的總重限制，k 物品的價值，而 b_k = a_k + 1 是物品的重量
而他題目要求的是「取了哪些物品」，可以在小於等於總重限制下讓價值總和最大
---
但因為他題目的 size 超小，物品只有 12 種，所以直接 brute-force 就好，10^12 = 4096
*/

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
        
        int maxPt = 0, maxTake = 0;
        
        for(int i = 0; i < (1 << 12); i++) {
            
            int pt = 0, cost = 0;
            for(int j = 0; j < 12; j++) {
                if(i & (1 << j)) {
                    pt += j;
                    cost = cost + aliceArrows[j] + 1;
                }
            }
            if(pt > maxPt && cost <= numArrows) {
                maxPt = pt;
                maxTake = i;
            }
        }
        
        
        vector<int> bob(12, 0);

        int curCost = 0;
        for(int i = 0; i < 12; i++) {
            if(maxTake & (1 << i)) {
                bob[i] = aliceArrows[i] + 1;
                curCost += bob[i];
            }
        }
        bob[0] = numArrows - curCost;

        return bob;
    }
};

// brute-force 結果 100% ？？？？
/*
Runtime: 53 ms, faster than 100.00% of C++ online submissions for Maximum Points in an Archery Competition.
Memory Usage: 10.1 MB, less than 81.25% of C++ online submissions for Maximum Points in an Archery Competition.
*/
