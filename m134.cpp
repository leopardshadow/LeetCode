
// 2022.1.21

/*
像這種題目給的條件好限制，都是特別設計的題目..
---
參考網路的解法，用到 greedy
想法是 如果 i 出現負的，代表我們不能從 start 開始走到 i，
必須是 i+1 開始走到底，circular 回頭，經原 start 再到 i
此時 start 被移動到 i+1

所以這裡更新 curGas 是放在判斷條件之後

好酷的做法
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0, costSum = 0;
        for(const int &g : gas)
            gasSum += g;
        for(const int &c : cost)
            costSum += c;
        if(gasSum < costSum)
            return -1;
        int curGas = 0, start = 0;
        for(int i = 0; i < gas.size(); i++) {
            if(curGas < 0) {
                start = i;
                curGas = 0;
            }
            curGas = curGas + gas[i] - cost[i];
        }
        return start;
    }
};

/*
Runtime: 122 ms, faster than 11.92% of C++ online submissions for Gas Station.
Memory Usage: 49.9 MB, less than 45.28% of C++ online submissions for Gas Station.
*/
