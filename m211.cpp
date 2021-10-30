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