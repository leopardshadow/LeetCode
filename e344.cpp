
void reverseString(char* s, int sSize){
    for(int i = 0; i < sSize / 2; i++) {
        char c = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = c;
    }
}
/*
Runtime: 52 ms, faster than 28.66% of C online submissions for Reverse String.
Memory Usage: 12.4 MB, less than 63.36% of C online submissions for Reverse String.
*/


//******************************************************************************//
// 2022.4.1

/*
愚人節 Leetcode 怎麼沒有特別活動呢 XD
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i++)
            swap(s[i], s[s.size() - 1 - i]);
    }
};
