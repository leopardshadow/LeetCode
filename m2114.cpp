// Biweekly Contest 68
// Dec 25, 2021

/*
一開始原本想用 FSM 狀態在那邊轉轉轉來解，但仔細看了題目後發現不用這麼麻煩
因為他限制很多
* 空白不能在頭、尾
* 不會連續出現空白
* 不會有空字串
所以走過一次數有幾個空白，+1 就是該句子的 words 數量了
*/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 1;
        for(auto s : sentences) {
            int cnt = 1;
            for(char c : s) {
                if(c == ' ')
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 93.75% of C++ online submissions for Maximum Number of Words Found in Sentences.
Memory Usage: 10.3 MB, less than 37.50% of C++ online submissions for Maximum Number of Words Found in Sentences.
*/
