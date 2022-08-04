
// 2022.8.4

/*
參考了 https://leetcode.com/problems/mirror-reflection/discuss/938821/Python-pure-geometry-illustrated

他的圖畫得很好
幾何苦手的 Me: QQ

0 3 0 3 0 3
1 2 1 2 1 2
0 3 0 3 0 3
1 2 1 2 1 2

好像把它想得太複雜的！
q 的那個點只會在東的邊上，不會在北！
不會從 3 出來
*/

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int k = 1;
        while ((k * q) % p)
            k++;
        if (k % 2 == 0) {
            if ((k * q / p) % 2 == 0)
                return 3;  // not happen; SW
            else
                return 2;
        }
        else {  // k == 1
            if ((k * q / p) % 2 == 0)
                return 0;
            else
                return 1;
        }
    }
};
