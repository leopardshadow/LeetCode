// backtracking

/*
這題前面 WA 了好幾次，都是建表時不小心打錯
*/

class Solution {
    vector<string> ans;
    string s;
    vector<string> i2char[8];
public:
    void comb(int i, string &digits) {
        if (i == digits.size()) {
            if(s != "")
                ans.push_back(s);
            return;
        }
        for(string c : i2char[digits[i] - '2']) {
            s += c;
            comb(i+1, digits);
            s = s.substr(0, s.length() - 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        i2char[0] = {"a", "b", "c"};
        i2char[1] = {"d", "e", "f"};
        i2char[2] = {"g", "h", "i"};
        i2char[3] = {"j", "k", "l"};
        i2char[4] = {"m", "n", "o"};
        i2char[5] = {"p", "q", "r", "s"};
        i2char[6] = {"t", "u", "v"};
        i2char[7] = {"w", "x", "y", "z"};
        comb(0, digits);
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.7 MB, less than 38.43% of C++ online submissions for Letter Combinations of a Phone Number.
*/


//******************************************************************************//
// 2022.5.9

class Solution {
    vector<string> ans;
    vector<string> tables = {"", "", "abc", "def", "ghi", "jkl", 
                             "mno", "pqrs", "tuv", "wxyz"};
public:
    
    void cal(const string &digits, int index, string number) {
        if (index >= digits.length())
            ans.push_back(number);
        else {
            for (int i = 0; i < tables[digits[index] - '0'].length(); i++)
                cal(digits, index + 1, number + tables[digits[index] - '0'][i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if (digits.length())
            cal(digits, 0, "");
        
        return ans;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.6 MB, less than 60.00% of C++ online submissions for Letter Combinations of a Phone Number.
*/
