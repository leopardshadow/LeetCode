
// Weekly Contest 273
// Dec 26
// NP P4 崩潰 QQ

/*
這題問把數字 reverse 兩次後誰會一樣
其實就是在問誰尾巴有 0，他會在第一次 reverse 時被消掉
而且題目很好心得把 0 這個測資寫在 Example，這是唯一需要特別檢查的 case
*/

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num == 0)
            return true;
        return (num % 10) != 0;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for A Number After a Double Reversal.
Memory Usage: 5.9 MB, less than 75.00% of C++ online submissions for A Number After a Double Reversal.
*/
