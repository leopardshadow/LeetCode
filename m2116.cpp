
// Biweekly Contest 68
// Dec 25, 2021

/*
這種括號匹配題一開始我想 backtracking 去找所有可能
但在寫的時候發現，從頭開始，每次遇到 '(' 會 +1，遇到 ')' 則是會 -1
invalid 的條件是出現負數或是結束時不是 0
這裡就可以用到 greedy，從頭開始可以置換的我都先填 '('
所以整個過程就是先數不能動的 ( ) 有幾個，接從頭開始填 (，填完可以有的 ( 後全塞 )
*/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        if(s.length() % 2)
            return false;
        
        int n1 = s.length() / 2, n2 = n1;
        int st = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(locked[i] == '1') {
                if(s[i] == '(')
                    n1--;
                else
                    n2--;
            }
        }
        
        for(int i = 0; i < s.length(); i++) {
         
            // not locked
            if(locked[i] == '0') {
                if(n1 > 0) {
                    s[i] = '(';
                    n1--;
                }
                else {
                    s[i] = ')';
                    n2--;
                }
                    
            }
            
            if(s[i] == '(') {
                st++;
            }
            else {
                st--;
                if(st < 0)
                    return false;
            }
        }
        return st == 0;

    }
};
