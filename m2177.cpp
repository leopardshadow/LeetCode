
// 可以一分鐘解掉的 Medium

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num % 3 != 0)
            return {};
        else
            return {num / 3 - 1, num / 3, num / 3 + 1};
    }
};

/*
Runtime: 3 ms, faster than 42.53% of C++ online submissions for Find Three Consecutive Integers That Sum to a Given Number.
Memory Usage: 5.9 MB, less than 95.05% of C++ online submissions for Find Three Consecutive Integers That Sum to a Given Number.
*/


// 這樣才有 100%，沒浪費時間多做除法
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num % 3 != 0)
            return {};
        else {
            long long t = num / 3;
            return {t - 1, t, t + 1};
        }
            
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Three Consecutive Integers That Sum to a Given Number.
Memory Usage: 6.1 MB, less than 24.32% of C++ online submissions for Find Three Consecutive Integers That Sum to a Given Number.
*/
