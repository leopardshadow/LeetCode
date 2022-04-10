
// 2022.4.10
// Weekly Contest 288

/*
考的是字串處理，全部舉列舉出來就好
*/

class Solution {
    int f(string s) {
        if (s == "")
            return 1;
        else
            return atoi(s.c_str());
    }
public:
    string minimizeResult(string exp) {
        int minNum = INT_MAX;
        int addPos;
        for (int i = 0; i < exp.length(); i++)
            if (exp[i] == '+')
                addPos = i;
        
        string s1 = exp.substr(0, addPos),
               s2 = exp.substr(addPos + 1);
        
        // a (b + c) d
        // a, d might be ""; b, c cannot be "" --> range of the for-loop
        
        string a, b, c, d;
        vector<string> ss(4);
        
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                a = s1.substr(0, i);
                b = s1.substr(i);
                c = s2.substr(0, j);
                d = s2.substr(j);
                int val = f(a) * (f(b) + f(c)) * f(d);
                // cout << a + "(" + b + "+" + c +")" + d << " = " << val << endl;
                if (val < minNum) {
                    minNum = val;
                    ss = {a, b, c, d};
                }
            }
        }
        
        
        return ss[0] + "(" + ss[1] + "+" + ss[2] +")" + ss[3];
    }
};
// 哇！！！ 應該是第一次雙 100.00%
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimize Result by Adding Parentheses to Expression.
Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Minimize Result by Adding Parentheses to Expression.
*/
