
// 2022.6.19

/*
一開始 TLE，參考其他人的作法後發現很多地方可以加速
---
要找到 prefix 是 word 的所有字，先移動 pointer 到那個 trie node，要找所有就從他後面開始找
從這時候開始那個 prefix 就已經不重要了，他的資訊已經藏在 trie node 裡
一開始我把他混在一起寫，變得很亂，同一個 function 要 match prefix 的第幾個字，同時也可能是 a-z 自由的選字
---
只要找 3 個，這點已經存在 vector 裡，就不用另外開一個 int 來存剩下多少
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
    
    void insert(string word) {
        int i;
        TrieNode *cur = root;
        for(int c = 0; c < word.length(); c++) {
            i = word[c] - 'a';
            if (!cur->child[i]) {
                cur->child[i] = new TrieNode();
            }
            cur = cur->child[i];
        }
        cur->isWord = true;
    }
    
    bool searchW(TrieNode *node, vector<string> &v, string s) {
        
        if (v.size() == 3)
            return true;  // ends early
                
        if (node->isWord)
            v.push_back(s);
            
        for (int i = 0; i < 26; i++) {
            if (node->child[i] &&
                searchW(node->child[i], v, s+string(1, 'a'+i)))
                return true;
        }
        
        return false;
    }
    
    vector<string> search(string w) {
        vector<string> ret;
        TrieNode *node = root;
        for (int i = 0; i < w.length(); i++) {
            node = node->child[w[i] - 'a'];
            if (!node)
                return ret;
        }
        searchW(node, ret, "");
        for (string &s : ret)
            s = w + s;
        return ret;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        // trie
        Trie trie;
        for (const string &p : products)
            trie.insert(p);
        
        // search
        vector<vector<string>> ans;
        ans.reserve(products.size());
        for (int i = 1; i <= searchWord.size(); i++)
            ans.push_back(trie.search(searchWord.substr(0, i)));
        
        return ans;
    }
};
/*
Runtime: 802 ms, faster than 14.42% of C++ online submissions for Search Suggestions System.
Memory Usage: 365.5 MB, less than 9.78% of C++ online submissions for Search Suggestions System.
*/
