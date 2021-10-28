/*
Hint. sliding window
每次移動後不要重數整個字串
*/

class Solution {
public:
    
    int cnt[26];
    
    bool check() {
        for(int i = 0; i < 26; i++)
            if(cnt[i] != 0)
                return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) return false;
        
        int n1 = s1.length();
        
        for(int i = 0; i < n1; i++) {
            cnt[s1[i] - 'a']++;
        }
        for(int i = 0; i < n1; i++) {
            cnt[s2[i] - 'a']--;;
        }
        if(check()) {
            return true;
        }
        
        for(int i = n1; i < s2.length(); i++) {
            
            cnt[s2[i - n1] - 'a'] += 1;
            cnt[s2[i] - 'a'] -= 1;            

            if(check()) {
                return true;
            }
        }
        
        return false;
    }
};

/*
Runtime: 4 ms, faster than 96.86% of C++ online submissions for Permutation in String.
Memory Usage: 7.1 MB, less than 98.75% of C++ online submissions for Permutation in String.
*/