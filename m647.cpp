class Solution {
private:
    bool isP(string s) {
        int n = s.length();
        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
    bool isP(string s, int l, int r) {
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        int step;
        // |---|  
        // y x a x y
        for(int i = 0; i < s.length(); i++) {
            step = 0;
            while(i - step >= 0 && i + step < s.length()) {
                if(isP(s, i - step, i + step)) {
                    ans ++;
                    step++;
                }
                else {
                    break;
                }
            }
        }
        // x a a x
        // 
        for(int i = 0; i < s.length() - 1; i++) {
            step = 0;
            while(i - step >= 0 && i + step + 1 < s.length()) {
                if(isP(s, i - step, i + step + 1)) {
                    ans ++;
                    step++;
                }
                else {
                    break;
                }
            }
        }

        return ans;
    }
};

/*
Runtime: 344 ms, faster than 9.83% of C++ online submissions for Palindromic Substrings.
Memory Usage: 383.7 MB, less than 8.53% of C++ online submissions for Palindromic Substrings.
*/