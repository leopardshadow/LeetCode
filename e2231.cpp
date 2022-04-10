
// 2022.4.10
// Weekly Contest 288

/*
一開始搞錯題目意思，奇數偶數 vs. 奇數位偶數位...
範例測資給的好爛，無法區分這兩個
*/

class Solution {
public:
    int largestInteger(int num) {
        
        string s = to_string(num), s0, s1, sa;
        
        for(char c : s) {
            if (c % 2 == 0)
                s0.push_back(c);
            else
                s1.push_back(c);
        }
        
        sort(s0.begin(), s0.end());
        sort(s1.begin(), s1.end());
        
        reverse(s0.begin(), s0.end());
        reverse(s1.begin(), s1.end());
        
        cout << s0 << " " << s1 << endl;
        
        int i0 = 0, i1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] % 2 == 0)
                sa.push_back(s0[i0++]);
            else
                sa.push_back(s1[i1++]);
        }
        
        return atoi(sa.c_str());
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest Number After Digit Swaps by Parity.
Memory Usage: 6 MB, less than 88.89% of C++ online submissions for Largest Number After Digit Swaps by Parity.
*/
