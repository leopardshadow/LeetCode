
// 2022.5.11

/*
這題是考高中的排列組合，n 顆球，4 個隔板排列
n = 1: (1+4)! / 1! 4! = 5
n = 2: (2+4)! / 2! 4! = 15
...
Ans: (n + 4) ! / n! 4! = (n+4) (n+3) (n+2) (n+1) / 24

因為 n 最大只有 50，所以 (n+_) 這 4 個東西乘起來還會在 int 的範圍內，不用擔心 overflow 的問題
*/

class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4) * (n+3) * (n+2) * (n+1) / 24;
    }
};
/*
Runtime: 3 ms, faster than 45.39% of C++ online submissions for Count Sorted Vowel Strings.
Memory Usage: 5.9 MB, less than 85.48% of C++ online submissions for Count Sorted Vowel Strings.
*/
