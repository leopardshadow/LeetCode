
// Biweekly Contest 79

/*
就照他說的做 XD
*/

class Solution {
public:
    bool digitCount(string num) {
        int cnt[12] = { 0 };
        for (char &c : num)
            cnt[c - '0']++;
        for (int i = 0; i < num.length(); i++)
            if (num[i] - '0' != cnt[i])
                return false;
        return true;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Number Has Equal Digit Count and Digit Value.
Memory Usage: 6 MB, less than 60.00% of C++ online submissions for Check if Number Has Equal Digit Count and Digit Value.
*/
