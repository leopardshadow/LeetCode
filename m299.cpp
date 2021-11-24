// Google

/*
就幾 A 幾 B 的題目，不太懂為什麼在 medium XDD
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int charSecret[10] = {0}, charGuess[10] = {0};
        int cntA = 0, cntB = 0;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i])
                cntA++;
            else {
                charSecret[secret[i] - '0']++;
                charGuess[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++) {
            cntB += min(charSecret[i], charGuess[i]);
        }
        return to_string(cntA) + "A" + to_string(cntB) + "B";
    }
};

/*
Runtime: 7 ms, faster than 30.11% of C++ online submissions for Bulls and Cows.
Memory Usage: 6.6 MB, less than 40.33% of C++ online submissions for Bulls and Cows.
*/
