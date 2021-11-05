/*
這題還有數學的解法，不過我看到比較有趣的是 binary search
對於一個 n，其實我要找的是數字 k，讓 n - (1 + 2 + ... + k) < k + 1
而且要恰恰好是第一個滿足這條不等式的 (最小的 k)

要特別注意，根據題目的 spec，在計算 (1 + 2 + ... + k) 時，如果先用梯形公式算出和，用 int 會超過
*/

class Solution {
public:
    
    }
};






/*
curC : 1   2   3
sum  : 0 1   3   6
n = 5
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int curC;
        for(curC = 1; n >= 0; curC++) {
            n -= curC;
            // 如果 sum = 0 ，然後慢慢用加的，可能會 overflow，超出正的範圍
            // 但如果是用減的，就還有負那邊可以緩衝
        }
        return curC - 2;
    }
};

/*
Runtime: 8 ms, faster than 44.64% of C++ online submissions for Arranging Coins.
Memory Usage: 5.8 MB, less than 96.10% of C++ online submissions for Arranging Coins.
*/