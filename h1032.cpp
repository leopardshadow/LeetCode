// 2021.12.4

/*
錯誤的想法

*/
// class StreamChecker {
//     bool alpha[26];
// public:
//     StreamChecker(vector<string>& words) {
//         for(int i = 0; i < 26; i++)
//             alpha[i] = false;
//         for(string word : words) {
//             alpha[word.back() - 'a'] = true;   
//         }
//     }
    
//     bool query(char letter) {
//         return alpha[letter - 'a'];
//     }
// };



/*
Hint: build the trie backwards

這題其實只是 Trie 的變形，要改成倒著長 (abcd 長的順序是 d -> c -> b -> a)
因為參數的 size 會很大，所以直接 call by value 複製的話會 TLE
同一份 code 改成 call by reference (怕改到，多個 const) 就過了
還從 TLE 變成 faster than 97.41% ...
這對執行時間的影響好大
*/


class TrieNode {
public:
    //
    TrieNode* alpha[26];
    bool isWord;
    //
    TrieNode() {
        for(int i = 0; i < 26; i++)
            alpha[i] = NULL;
        isWord = false;   
    }
};

class Trie {
    TrieNode *head;
public:
    //
    Trie() {
        head = new TrieNode();   
    }
    //
    void add(const string &s) {
        TrieNode *cur = head;
        int c;
        for(int i = s.length() - 1; i >= 0; i--) {
            c = s[i] - 'a';
            if(!cur->alpha[c]) {
                cur->alpha[c] = new TrieNode(); 
            }
            cur = cur->alpha[c];
        }
        cur->isWord = true;
    }
    //
    bool search(const string &s) {
        TrieNode *cur = head;
        int c;
        for(int i = s.length() - 1; i >= 0; i--) {
            c = s[i] - 'a';
            if(!cur->alpha[c])
                return false;
            else if(cur->alpha[c]->isWord)
                return true;
            cur = cur->alpha[c];
        }
        return false;
    }
};


class StreamChecker {
    string stream;
    Trie trie;
public:
    StreamChecker(vector<string>& words) {
        for(string w : words)
            trie.add(w);
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        return trie.search(stream);
    }
};

/*
Runtime: 192 ms, faster than 97.41% of C++ online submissions for Stream of Characters.
Memory Usage: 105.8 MB, less than 54.98% of C++ online submissions for Stream of Characters.
*/
