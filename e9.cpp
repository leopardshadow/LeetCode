
// () 2022.3.30

/*
今天的 daily 之前寫過直接 submit，來補個沒寫過的，先挑 easy 來寫 XD
---
在遇到 int palindrone 時可以轉成 string 來做比較簡單，還比較快
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        // vector<int> xs;
        // while (x) {
        //     xs.push_back(x % 10);
        //     x /= 10;
        // }
        string xs = to_string(x);
        for (int i = 0; i < xs.size() / 2; i++)
            if (xs[i] != xs[xs.size() - 1 - i])
                return false;
        return true;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Palindrome Number.
Memory Usage: 5.9 MB, less than 75.55% of C++ online submissions for Palindrome Number.
*/
