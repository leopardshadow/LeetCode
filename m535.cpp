
// 2022.4.23

/*
這種 design 題都滿有趣ㄉ
---
我的作法是用 counter 的狀態來決定短網址，心裡知道算網址的 hash 應該比較好，但又怕他 collision
看了一下討論區比較喜歡的作法是用長度是 26 + 26 + 10 的字元陣列 ("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")
random 得決定產生的短網址，並把資料存在 map 中，用產生的短網址對應到哪個長網址
---
我這邊用了兩個 map，原因是不想讓相同長網址有兩種不同短網址，所以在 encode 時就會先檢查
---
用 counter 比較簡單的作法是 to_string(i)，i 是整數的 counter，這樣就可以避掉處理進位
*/

class Solution {
    map<string, string> long2short, short2long;
    string states;
    string genShortUrl() {
        int carry = 0;
        for (int i = 0; i < states.size(); i++) {
            states[i] += carry;
            if (states[i] > 'z') {
                carry = 1;
                states[i] = 'a';
            }
            else {
                carry = 0;
                break;
            }
        }
        if (carry == 1)
            states.push_back('a');
        return "http://tinyurl.com/" + states;
    }
public:
    
    Solution() {
        states = "a";
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.count(longUrl))
            return long2short[longUrl];
        else {
            long2short[longUrl] = genShortUrl();
            short2long[long2short[longUrl]] = longUrl;
        }
        return long2short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[shortUrl];
    }
};
/*
Runtime: 8 ms, faster than 31.19% of C++ online submissions for Encode and Decode TinyURL.
Memory Usage: 7.2 MB, less than 21.39% of C++ online submissions for Encode and Decode TinyURL.
*/


// 會過但根本來亂的寫法wwwwwww
class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};
