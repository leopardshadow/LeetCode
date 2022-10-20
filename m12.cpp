
// 2022.10.20

/*
覺得不是一題很好的面試題
還要有對羅馬數字表示法的 sense
*/

class Solution {
public:
    string intToRoman(int num) {
        string a[10] = {"", "M", "MM", "MMM"};
        string b[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string c[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string d[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return a[num / 1000] + b[(num / 100) % 10] + c[(num / 10) % 10] + d[num %10];
    }        
};
/*
Runtime: 24 ms, faster than 28.06% of C++ online submissions for Integer to Roman.
Memory Usage: 6 MB, less than 77.21% of C++ online submissions for Integer to Roman.
*/
