/*
Trie copies from LC208 - https://leetcode.com/problems/implement-trie-prefix-tree/
*/

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
};

class WordDictionary {
public:
    
    TrieNode *root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        
        int i;
        TrieNode *cur = root;
        for(int c = 0; c < word.length(); c++) {
            i = word[c] - 'a';
            if(!cur->child[i]) {
                cur->child[i] = new TrieNode();
            }
            cur = cur->child[i];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return search(root, word);
    }

    bool search(TrieNode *cur, string word) {
        
        int i;
        for(int c = 0; c < word.length(); c++) {
            
            bool ret = false;
            if(word[c] == '.') {
                for(int a = 0; a < 26; a++) {
                    if(cur->child[a])
                        ret = ret | search(cur->child[a], word.substr(c+1));
                        // should be c+1 here, since we do the comparison here!
                }
                return ret;
            }
            
            i = word[c] - 'a';
            if(!cur->child[i]) {
                return false;
            }
            cur = cur->child[i];
        }
        return cur->isWord;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */




// 2022.1.28

/*
昨天也是 trie，但是是變形的，要先知道可以用 trie 解
這題就很直接一副我是 trie 的長相
---
但好久沒碰 trie，寫起來超卡的，真的要複習誒...
*/

class TrieNode {
public:
    bool isWord;
    TrieNode *child[26];
    TrieNode() {
        isWord = false;
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie {
    TrieNode *node, *cur;
public:
    Trie() {
        node = new TrieNode();
    }
    void insert(const string &word) {
        TrieNode *cur = node;
        for(int i = 0; i < word.length(); i++) {
            int nxt = word[i] - 'a';
            if(!cur->child[nxt])
                cur->child[nxt] = new TrieNode();
            cur = cur->child[nxt];
        }
        cur->isWord = true;
    }
    bool find(const string &word) {
        cur = node;
        return find(0, word);
    }
    bool find(int i, const string &word) {
        
        if(i == word.size())
            return cur && cur->isWord;
        
        if(!cur)
            return false;
        
        TrieNode *tmp = cur;
        if(word[i] == '.') {
            for(int j = 0; j < 26; j++) {
                cur = tmp->child[j];
                if(find(i+1, word))
                    return true;
            }
            return false;
        }
        
        int nxt = word[i] - 'a';
        if(cur && cur->child[nxt]) {
            cur = cur->child[nxt];
            return find(i+1, word);
        }
        else
            return false;
    }
};

class WordDictionary {
    Trie trie;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.find(word);
    }
};

/*
Runtime: 80 ms, faster than 78.73% of C++ online submissions for Design Add and Search Words Data Structure.
Memory Usage: 43.3 MB, less than 74.45% of C++ online submissions for Design Add and Search Words Data Structure.
*/
