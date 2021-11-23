// Google

/*
原本以為這題為什麼可以在 medium，寫下去才發現我想得太簡單了 QQ
我原本是想 greedy 得取，每次都拿頭、尾中最大的，但這樣不一定是最大值
例如：
[1 1 100 2 2 2] 取 3 個，答案會是 102，但按照上面取法只會拿到 6

所以感覺起來也是要走過一遍 ==> sliding window
sliding window 的題目小心範圍RRRRRRR
(感覺起來跟剛剛的 1525. Number of Good Ways to Split a String 好像喔
都是 sliding window 系的題目，只是取的方向不一樣)

我的寫法速度居然這麼爛 @@

因為不大相信所以再點了一次 submission，結果執行時間瞬間砍半，從 112 ms 變成 56 ms，只贏 8.79% 變成 74.41%
Hello????? 他時間只是參考用欸
還是在我兩次 submit 中間有一大堆人交 ; 或是因為 chche 所以比較快 (X
*/

// WRONG LOGIC
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int l = 0, r = cardPoints.size() - 1;
//         int sum = 0;
//         while(k) {
//             if(cardPoints[r] > cardPoints[l]) {
//                 sum += cardPoints[r];
//                 r--;
//             }
//             else {
//                 sum += cardPoints[l];
//                 l++;
//             }
//             k--;
//         }
//         return sum;
//     }
// };


/*
|---|
0 1 2 3 4 5
    -     +
  -     +
-     +
k = 3
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        // take k cards from left
        for(int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int maxSum = sum;
        // gradually removes one from left and take one from right
        for(int i = 0; i < k ; i++) {
            sum -= cardPoints[k - i - 1];
            sum += cardPoints[cardPoints.size() - 1 - i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};


/*
Runtime: 56 ms, faster than 74.41% of C++ online submissions for Maximum Points You Can Obtain from Cards.
Memory Usage: 42.5 MB, less than 48.82% of C++ online submissions for Maximum Points You Can Obtain from Cards.
*/
