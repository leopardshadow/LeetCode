
// 2022.6.18 618 昨天手機摔到 = = 今天剛好收到一些折價卷

/*
真的要仔細看題目說明欸，只看標題我以為是要回傳所有符合的字串，看了 return type 以為是要回傳個數，結果他是要 index，都猜錯 XDD
---
麻煩的字串搜索題目第一直覺是 trie，但他同時有 prefix 和 suffix，之前的都只要找某一邊
看了討論區 QQ
作法是 ***把某個字可能的 prefix - suffix 組合全部列出來***
以 apple 為例，他所有的 (prefix, suffix) 組合就是下面 25 個 (prefix, suffix 長度至少為 1)
(a, e),     (a, le),     (a, ple),     (a, pple),     (a, apple)
(ap, e),    (ap, le),    (ap, ple),    (ap, pple),    (ap, apple)
(app, e),   (app, le),   (app, ple),   (app, pple),   (app, apple)
(appl, e),  (appl, le),  (appl, ple),  (appl, pple),  (appl, apple)
(apple, e), (apple, le), (apple, ple), (apple, pple), (apple, apple)
---
因為題目只要求最大，所以就從小到大，遇到一樣就蓋掉
---
worst case 會造出 N L^2 的 map entries (N 個字串，字串長度為 L)
---
這題滿有趣ㄉ
---
也是可以用 trie 做，看是用 map 來找還是 trie 來找～
*/

class WordFilter {
    unordered_map<string,int> m;
public:
    WordFilter(vector<string>& words) {
        string temp;
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            for (int pL = 1; pL <= w.length(); pL++) {  // prefix length
                for (int sL = 1; sL <= w.length(); sL++) {  // suffix length
                    temp = w.substr(0, pL) + "." + w.substr(w.length() - sL, sL);
                    m[temp] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string targ = prefix + "." + suffix;
        if (m.find(targ) == m.end())
            return -1;
        else
            return m[targ];
    }
};
/*
Runtime: 1452 ms, faster than 5.23% of C++ online submissions for Prefix and Suffix Search.
Memory Usage: 153.9 MB, less than 59.70% of C++ online submissions for Prefix and Suffix Search.
*/
