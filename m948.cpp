
// 2022.9.12

/*
判斷條件好麻煩...
            if (score < 0)
                break;
這兩行是我一開始卡住的點，沒注意到題目的意思是 score 不能變成負值
只有在 score 可以減時才能減，不能先預支
*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, ans = 0;
        int i = 0, j = tokens.size();
        while (i < j) {
            if (score < 0)
                break;
            if (power < tokens[i]) {
                power += tokens[--j];
                score--;
            }
            else if (power >= tokens[i]) {
                power -= tokens[i++];
                score++;
                ans = max(ans, score);
            }
        }
        return ans;
    }
};
/*
Runtime: 19 ms, faster than 12.07% of C++ online submissions for Bag of Tokens.
Memory Usage: 10.5 MB, less than 94.44% of C++ online submissions for Bag of Tokens.
*/
