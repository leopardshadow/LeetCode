
// 2022.3.4

/*
這題題目滿有趣的，感覺就是 Google 會出的題目XD
下次要不要拿香檳去微波啊 
---
我一開始的想法是一杯一杯倒，所以卡住
比較簡單的想法是先當他放得下，超過 1.0 的部分再讓他往下流到下一層
---
題目的「形狀」有種帕斯卡三角形的感覺，但「數字」部分感覺怪怪的
以
 1 2 1
1 3 3 1
上下兩層的數字我現在找不到意義
---
這裡我是用二維陣列來存，其實可以壓成一維，只要 glass 走訪的順序從大到小，讓後面不會影響前面 + 最滿是一杯的判斷放在 return 那邊就行
---
想的一些 follow-up
---
一秒倒一杯，第 n 秒時哪一杯有多少水？
其實用目前這個作法也可以解，把 tower[0][0] 更新值再全部流一次就好，但比較花時間，要更新整張陣列
---
某些杯子有漏洞，一秒會漏多少水 (直接漏掉 or 灑到其他杯子裡)
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double tower[102][102] = { 0 };
        tower[0][0] = (double)poured;
        for(int r = 0; r <= query_row; r++) {
            for(int g = 0; g <= r; g++) {
                if(tower[r][g] > 1.) {
                    tower[r+1][g] += (tower[r][g] - 1.) / 2.;
                    tower[r+1][g+1] += (tower[r][g] - 1.) / 2.;
                    tower[r][g] = 1.0;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};

/*
Runtime: 4 ms, faster than 92.15% of C++ online submissions for Champagne Tower.
Memory Usage: 6 MB, less than 91.14% of C++ online submissions for Champagne Tower.
*/
