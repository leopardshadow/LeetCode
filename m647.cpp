class Solution {
private:
    string s;
    bool isP(int l, int r) {
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

public:
    int countSubstrings(string s) {
        this->s = s;
        int ans = 0;
        int step;
        // |---|  
        // y x a x y
        for(int i = 0; i < s.length(); i++) {
            step = 0;
            while(i - step >= 0 && i + step < s.length()) {
                if(isP(i - step, i + step)) {
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
                if(isP(i - step, i + step + 1)) {
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
Runtime: 164 ms, faster than 12.56% of C++ online submissions for Palindromic Substrings.
Memory Usage: 6.2 MB, less than 97.25% of C++ online submissions for Palindromic Substrings.
*/


// 2022.5.22
// 偷懶ww
