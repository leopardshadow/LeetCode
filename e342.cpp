
// 2022.8.22

/*
這種二進位的題目滿有趣的
有時候需要反過來思考 (XXX 會 <=> OOO 不會)
*/


class Solution {
public:
    bool isPowerOfFour(int n) {
        
        // n can not be <= 0 if can be be representad as 4^x
        if (n <= 0)
            return false;
        
        // n should has exactly one '1' in its binary representation
        if (n & (n - 1))
            return false;
        
        // 'the only 1' shoule be at even places, ... *-*-*-*
        // i.e. it cannot present at odd places
        if (n & 0xAAAAAAAA)
            return false;
        
        return true;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Four.
Memory Usage: 5.9 MB, less than 71.30% of C++ online submissions for Power of Four.
*/
