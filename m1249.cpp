
// 2022.3.15

/*
大致上是
原始的 s --倒著看拿掉多的 '(' --> s1 --正著看拿掉多餘的 ')' --> s2
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt;
        string s1, s2;
        
        reverse(s.begin(), s.end());
        
        cnt = 0;
        for(const char &c : s) {
            if(c == ')')
                cnt++;
            else if(c == '(') {
                if(cnt <= 0)
                    continue;
                else
                    cnt--;
            }
            s1.push_back(c);
        }

        reverse(s1.begin(), s1.end());
                
        cnt = 0;
        for(const char &c : s1) {
            if(c == '(')
                cnt++;
            else if(c == ')') {
                if(cnt <= 0)
                    continue;
                else
                    cnt--;
            }
            s2.push_back(c);
        }
        
        return s2;
    }
};

/*
Runtime: 42 ms, faster than 29.90% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
Memory Usage: 12.3 MB, less than 21.74% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
*/
