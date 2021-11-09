// Hint. length of the puzzle is only 7

/*
     a b c d e f 
ab   1 1 0 0 0 0 (word)
bcaf 1 1 1 0 0 1 (puzzle)
     0 0 0 1 1 0
 ----------------
     0 0 0 0 0 0


     a b c d e f 
df   0 0 0 1 0 1 (word)
bcaf 1 1 1 0 0 1 (puzzle)
     0 0 0 1 1 0
 ----------------
     0 0 0 1 0 0
*/

/*
這題主要在考 bit mask 的操作：

26 個小寫英文字母 --- 32 bit integer

1. word 包含 puzzle 第一個字元
2. word 的字由 puzzle 任意組合而成 (i.e. 不會再 word 找到 puzzle 裡沒有的)

1:
先取出 puzzle 的第一個字元，我們知道 word 在那位應該要被標成 1
所以 & 在一起，如果 word 包含 puzzle 的第一個字元，則那位是 1，結果會是非 0

2:
word 的字由 puzzle 任意組合而成，換句話說，對於所有 word 的字元，我們都可以在 puzzle mask 對應位置找到
並且**消掉他**，這裡消掉是 word & (~puzzle)
如此一來，如果 word 有的，但 puzzle 沒有的位會留著

到目前為止是我一開始的想法，time complexity 會是 O(mn)，會 TLE
---

但有個很關鍵的線索還沒用到：
length of the puzzle is only 7

?????

*/

class Solution {
public:
    
    unsigned int str2mask(string s) {
        unsigned int res = 0;
        for(int i = 0; i < s.length(); i++)
            res = res | (1 << (s[i] - 'a'));
        return res;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {        
        
        vector<int> ans;
        unsigned int puzz, word;
        int cnt;
        bool cond1, cond2;
        map< pair<char, int>, int> m;
        
        // vector<unsigned int> freq;
        map<int, int> freq;
        for(int j = 0; j < words.size(); j++) {
            // freq.push_back(str2mask(words[j]));
            // freq[make_pair(words[j][0], str2mask(words[j]))]++;
            freq[str2mask(words[j])]++;
        }
        
        for(int i = 0; i < puzzles.size(); i++) {
            
            puzz = str2mask(puzzles[i]);
            
            if(m.find(pair<char, int>(puzzles[i][0], puzz)) != m.end()) {
                ans.push_back(m[make_pair(puzzles[i][0], puzz)]);
                continue;
            }
            
            cnt = 0;
            
            // for all subsets of puzzle, accumulates its frequency
            
            unsigned int subset;
            
            // for(subset = puzz; subset != 0; subset = (subset - 1) & puzz ) {
            //     cnt += freq[make_pair(puzzles[i][0], subset)];
            // }

            for(subset = puzz; subset != 0; subset = (subset - 1) & puzz ) {
                if(subset & (1 << puzzles[i][0]-'a'))
                    cnt += freq[subset];
            }

            
//             for(auto it = freq.begin(); it != freq.end(); it++) {
                
//                 word = it->first;
                
//                 // word contains the first letter of puzzle
//                 cond1 = word & (1 << (puzzles[i][0] - 'a'));  // should be 1
//                 if(!cond1) continue;
                
//                 // for each letter in word, that letter is in puzzle
//                 cond2 = word & (~puzz); // should be 0
//                 if(cond2) continue;
                
//                 cnt += it->second;
//             }
            
            
            m[pair<char, int>(puzzles[i][0], puzz)] = cnt;
            ans.push_back(cnt);
        }
        return ans;
    }
};

/*
Runtime: 284 ms, faster than 52.38% of C++ online submissions for Number of Valid Words for Each Puzzle.
Memory Usage: 49.7 MB, less than 40.95% of C++ online submissions for Number of Valid Words for Each Puzzle.
*/