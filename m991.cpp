
// 2022.3.23

/*
這題把 startValue 和 target 反過來比較好做
變成 除二 和 加一 兩種操作
從 x 要變成 y
 (1) 如果 x > y  可以的話就除二，不然只能加一 ***[1]***
 (2) 如果 x == y Done;
 (3) 如果 x < y  操作 (y - x) 次加一就能到 y

[1] 這裡就是正著做麻煩的地方，因為乘二對數字沒有要求，但除二會有，必須是二的倍數
---
greedy 的題目有想到 greedy rule 就很簡單，但沒想到就 ... QQ
雖然一開始有反著做的想法，但看了討論區才寫出來
---
我原本想這題可以出的 follow-up 是操作還有 ×3，但好像沒有簡單的 greedy rule wwwww
*/

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target > startValue) {
            ans++;
            if(target % 2 == 0)
                target /= 2;
            else
                target++;
        }
        ans += (startValue - target);
        return ans;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Broken Calculator.
Memory Usage: 5.8 MB, less than 73.18% of C++ online submissions for Broken Calculator.
*/
