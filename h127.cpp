
// 2022.2.12

/*
從題目的敘述就有一種很 graph - bfs 的感覺 XD
雖然知道方向，但是怎麼將 code 寫得好看 + 不會 TLE 要想一下
---
忘了之前寫哪一題，也有用到同樣的技巧：
兩兩 word 比較相比 vs. 每一位逐一去試 a-z
後者會比較快
前面那個需要 word 數量平方的時間
後面則是 26 × word 本身長度
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int step = 0;
        set<string> ws;
        for(const string &s : wordList)
            ws.insert(s);
        
        if(ws.count(endWord) == 0)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()) {
            
            int qSize = q.size();
            step += 1;
            
            for(int i = 0; i < qSize; i++) {
                
                string word = q.front();
                q.pop();
                
                for(int i = 0; i < word.length(); i++) {
                    
                    string s = word;
                    for(int c = 'a'; c <= 'z'; c++) {
                        s[i] = c;
                        if(s == endWord)
                            return step + 1;  // ends earlier
                        if(ws.count(s)) {
                            q.push(s);
                            ws.erase(s);
                        }
                    }
                }   
            }
        }
        
        return 0;
    }
};

/*
Runtime: 467 ms, faster than 37.79% of C++ online submissions for Word Ladder.
Memory Usage: 14 MB, less than 63.77% of C++ online submissions for Word Ladder.
*/
