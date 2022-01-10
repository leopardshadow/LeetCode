
// 2022.1.10

/*
我是覺得先把他 reverse 後再做比較好懂，畢竟我們做加法時，也是個、十、百、千這樣往上的順序
*/

class Solution {
    void reverse(string &s) {
        for(int i = 0; i < s.length() / 2; i++)
            swap(s[i], s[s.length() - 1 - i]);
    }
public:
    string addBinary(string a, string b) {
        int c = 0, r;
        string ans;
        
        reverse(a);
        reverse(b);
        
        while(a.length() < b.length())
            a.push_back('0');
        while(a.length() > b.length())
            b.push_back('0');

        for(int i = 0; i < a.length(); i++) {
            r = (a[i] - '0') + (b[i] - '0') + c;
            c = (r >= 2);
            r %= 2;
            ans.push_back('0' + r);
        }
        
        if(c)
            ans.push_back('1');
        
        reverse(ans);
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 61.32% of C++ online submissions for Add Binary.
Memory Usage: 6.4 MB, less than 59.51% of C++ online submissions for Add Binary.
*/
