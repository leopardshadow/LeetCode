
// 2022.1.23

/*
這題看了 hint 之後大概有一些想法，但要怎麼寫得漂亮又花了一些時間思考
---
題目給的 hint 1 是產生所有可能 ; hint 2 是固定前面的，產生後面的 digits
關於如何產生「後面的」，我有兩個想法
 - 1. +11..1  e.g. 123 + 111 = 234, 234 + 111 = 345, 一直加，直到出現 9 就不能再加了
 - 2. 對 n 來說，他後面是 10 * n + (n % 10 + 1)
 1 感覺好麻煩
我後來用 2，但這樣他的順序不會是由小到大 (如果只比相同位數才會)，所以最後才塞了 sort，好意外 100.00% faster
---
和 YC 討論，他們做法是造一個 123456789 的字串，接著 substr
1"234"56789
12"345"6789
這種感覺
---
看了一下討論區，也有幾個人用 sort
但是!!!! 有人用查表，我還真沒想到這招!!!!!
畢竟因為要連續數字，所以解的空間很小 (12, 23, 34, ..., 89, 123, 234, ... 789, ..., 123456789)
有時候太執著跳下去想一個「所謂好的算法」了，查表這樣的解法就很精簡，很完美得解出這題XD
*/

class Solution {
    vector<int> ans;
    void enumerate(int n, int &low, int &high) {
        if(n >= low && n <= high)
            ans.push_back(n);
        if(n > high || n % 10 == 9)
            return;
        enumerate(10 * n + n % 10 + 1, low, high);
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i <= 9; i++)
            enumerate(i, low, high);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// 我一開始這樣的寫法居然是 100.00% faster，這其中一定有什麼誤會wwwwww
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sequential Digits.
Memory Usage: 6.3 MB, less than 36.79% of C++ online submissions for Sequential Digits.
*/
