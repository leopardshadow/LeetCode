
// 2022.11.7

/*
greedy
*/

class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        int i = 0;
        while (i < n.size() && n[i] == '9')
            i++;
        if (i < n.size())
            n[i] = '9';
        return stoi(n);
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
Memory Usage: 5.9 MB, less than 82.75% of C++ online submissions for Maximum 69 Number.
*/
