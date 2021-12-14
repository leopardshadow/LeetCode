class Solution {
public:
    string minWindow(string s, string t) {
        
        int alpha[26] = { 0 }, orig[26] = { 0 };
        
        for(char c : t) {
            alpha[c - 'A']++;
            orig[c - 'A']++;
        }
            
        int matched = t.length();
        
        int l = 0;
        string ans = s;
        
        //
        while(alpha[s[l] - 'A' ] == 0)
            l++;
        
        //
        int r = l;
        while(matched != 0 && r < s.length()) {            
            if(alpha[s[r] - 'A' ] > 0) {
                alpha[s[r] - 'A' ]--;
                matched--;
            }
            r++;
        }
        
        ans = s.substr(l, r - l);
        
        s[l, r) is a window substring, probably not min
        
        l++;
        
        while(r < s.length()) {
            
            // move l
            while(orig[s[l] - 'A'] == 0) {
                l++;
            }
            
            // move r
            while(s[l] != s[r] && r < s.length()) {
                r++;
            }
            
            if(r - l + 1 < ans.length())
                ans = s.substr(l, r - l + 1);
            
            l++;
            r++;
        }
        
        return ans;
    }
};
