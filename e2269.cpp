
// Biweekly Contest 78

/*
int <-> string 轉換
*/

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        for (int i = 0; i + k <= s.length(); i++) {
            int n = stoi(s.substr(i, k));
            if (n != 0 && num % n == 0)
                ans++;
        }
        return ans;
    }
};
