
// 2022.1.24

/*
算是一題簡單的 FSM
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1)
            return true;
        // ASCII 65 - A
        // ASCII 97 - a
        bool allCap;  // true / false - should be upper / lower case
        if(word[0] < 97 && word[1] < 97)  // US A
            allCap = true;
        else if(word[0] < 97 && word[1] >= 97)  // Go ogle
            allCap = false;
        else if(word[0] >= 97 && word[1] >= 97)  // le etcode
            allCap = false;
        else  // aB
            return false;
        for(int i = 2; i < word.size(); i++) {
            if((word[i] < 97) ^ allCap)  // 酷XD
                return false;
        }
        return true;
    }
};

/*
Runtime: 4 ms, faster than 27.21% of C++ online submissions for Detect Capital.
Memory Usage: 6.2 MB, less than 19.00% of C++ online submissions for Detect Capital.
*/
