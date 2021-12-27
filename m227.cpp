
// 2021.12.25

/*
這題乍看之下是手刻 reverse polish notation 的題目
但因為沒有 ()，且只有兩種 priority 的 operation，所以其實可以不用用到 RPN
---
大致的概念是遇到 * 和 / 才把 stack 的東西抓出來計算，遇到 + 或 - 就直接 push 進去
但因為是先出現 operator 才出現 operand，就有點 delay 的感覺
最後用很奇怪的方式寫出來 ><
速度和用的空間都好差 :(
*/

class Solution {
public:
    int calculate(string s) {
        
        stack<long long> ns;
        int n = 0;
        int i = 0;
        int x;
        char todo = 'x';
        
        s = s + "$";
        
        for(int i = 0; i < s.length(); i++) {
            
            char c = s[i];
            
            if(c >= '0' && c <= '9') {
                n = n * 10 + (c - '0');
            }
            else if(c == ' ')
                continue;
            else {
                
                if(todo == '*') {
                    int x1 = ns.top();
                    ns.pop();
                    ns.push(x1 * n);
                    todo = 'Y';
                }
                else if(todo == '/') {
                    int x1 = ns.top();
                    ns.pop();
                    ns.push(x1 / n);
                    todo = 'Y';
                }
                else if(todo == '-') {
                    ns.push(-n);
                    todo = 'Y';
                }
                
                switch(c) {
                    case '+':
                        if(todo == 'x')
                            ns.push(n);
                        break;
                    case '-':
                        if(todo == 'x')
                            ns.push(n);
                        todo = '-';
                        break;
                    case '*':
                    case '/':
                        if(todo == 'x')
                            ns.push(n);
                        todo = c;
                        break;
                    case '$':
                        if(todo == 'x')
                            ns.push(n);
                }
                n = 0;
                if(todo == 'Y')
                    todo = 'x';
            }
        }
        
        int ans = 0;
        while(!ns.empty()) {
            ans += ns.top();
            ns.pop();
        }
        return ans;
    }
};

/*
Runtime: 18 ms, faster than 18.35% of C++ online submissions for Basic Calculator II.
Memory Usage: 9.8 MB, less than 8.73% of C++ online submissions for Basic Calculator II.
*/
