/*
Notes.
1. 以空間換取時間
2. 另外建一個 TrieNode 的 class
*/

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
};

class Trie {
public:
    
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
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
        int i;
        TrieNode *cur = root;
        for(int c = 0; c < word.length(); c++) {
            i = word[c] - 'a';
            if(!cur->child[i]) {
                return false;
            }
            cur = cur->child[i];
        }
        return cur->isWord;
    }

    
    bool startsWith(string prefix) {
        int i;
        TrieNode *cur = root;
        for(int c = 0; c < prefix.length(); c++) {
            i = prefix[c] - 'a';
            if(!cur->child[i]) {
                return false;
            }
            cur = cur->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/*
Runtime: 60 ms, faster than 63.07% of C++ online submissions for Implement Trie (Prefix Tree).
Memory Usage: 45.1 MB, less than 44.64% of C++ online submissions for Implement Trie (Prefix Tree).
*/