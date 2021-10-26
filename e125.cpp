class Solution {
private:
    bool an(char c) {  // alphanumeric
        return (c >= '0' && c <= '9') || 
               (c >= 'A' && c <= 'Z') || 
               (c >= 'a' && c <= 'z');
    }
    // 48 65 97  97 - 65 = 32 = 100000
    //. 0  A. a
    bool equal(char a, char b) {
        int m = 32;
        return (a | m) == (b | m);
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l <= r) {
            while(l < s.length() && !an(s[l]))
                l++;
            while(r >= 0 && !an(s[r]))
                r--;
            if(l == s.length() || r == -1)
                break;
            if(!equal(s[l], s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};