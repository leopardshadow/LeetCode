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



// 2022.2.11

/*
這題在看題目時花了一點點時間理解
回傳 true 的條件是 s2 包含 s1 的組合，包含指的是 substring
題目敘述的第二句只是在補充說明第二句..
---
前天以為是 sliding window 的題目結果是 prefix sum
今天就真的出一個 sliding window
---
寫完後看 Submission 才發現原來我之前寫過，居然沒什麼印象 笑死
複習很重要 +1
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length())
            return false;
        
        int cnt[26] = { 0 };
        for(int i = 0; i < s1.length(); i++) {
            cnt[s2[i] - 'a']++;
            cnt[s1[i] - 'a']--;
        }
            
        bool match = true;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] != 0)
                match = false;
        }
        if(match)
            return true;
        
        for(int i = s1.length(); i < s2.length(); i++) {
            
            cnt[s2[i - s1.length()] - 'a']--;
            cnt[s2[i] - 'a']++;
            
            match = true;
            for(int i = 0; i < 26; i++) {
                if(cnt[i] != 0)
                    match = false;
            }
            if(match)
                return true;
        }
        
        return false;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutation in String.
Memory Usage: 7.3 MB, less than 71.57% of C++ online submissions for Permutation in String.
*/
