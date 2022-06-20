
// 2022.6.20

/*
這題可以用 trie 來做，因為字串不可能在中間，一定要有 '#' 這個符號最為結尾
所以在建立 trie 時要從尾巴開始！
---
前面就和一般建 trie 同樣步驟，只是會把 word 倒過來插入
接下來再數數的部分，如果某個 node 是 word，但他下面還有 child，那他就不需要被計算，因為他會被包含在其他 word 裡
---
以這題 Example 1 來說，words = ["time", "me", "bell"]，他造出的 encoding 是 "time#bell#"，對應的 indices 是 [0, 2, 5]
"time#" 和 "bell#" 是完全獨立的，誰先誰後都沒差
一開始我還以為要 minmize indices 和，讓 0 + 2 + 5 這個數值最小，這樣的話就很麻煩了，應該是 DP (?)
*/

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
};

class Trie {
    TrieNode *root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string &word) {
        int i;
        TrieNode *cur = root;
        for (int c = 0; c < word.length(); c++) {
            i = word[c] - 'a';
            if (!cur->child[i]) {
                cur->child[i] = new TrieNode();
            }
            cur = cur->child[i];
        }
        cur->isWord = true;
    }
    
    void cntWord(TrieNode *curr, int &cnt, int len) {
        bool hasChild = false;
        for (int i = 0; i < 26; i++) {
            if (curr->child[i]) {
                hasChild = true;
                cntWord(curr->child[i], cnt, len+1);
            }
        }
        if (!hasChild && curr->isWord)
            cnt += (len + 1);  // +1 for #
    }
    
    int count() {
        int cnt = 0;
        cntWord(root, cnt, 0);
        return cnt;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        for (string &w : words) {
            reverse(w.begin(), w.end());
            trie.insert(w);
        }
        return trie.count();
    }
};
/*
Runtime: 96 ms, faster than 60.40% of C++ online submissions for Short Encoding of Words.
Memory Usage: 73.9 MB, less than 22.77% of C++ online submissions for Short Encoding of Words.
*/
