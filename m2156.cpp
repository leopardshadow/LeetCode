
// 這週 Weekly 的題目，沒參加，但還是寫寫看

/*
無腦照刻會 TLE QQ 
題目的 hint: rolling hash
*/

class Solution {
    int calHash(const string &s, int power, int modulo, int start, int k) {
        long long p = 1, hashV = 0;
        for(int i = 0; i < k; i++) {
            hashV = (hashV + p * (s[start + i] - 'a' + 1)) % modulo;
            p = (p * power) % modulo;
        }
        return hashV % modulo;
    }
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.length();
        for(int i = 0; i + k - 1 < n; i++) {
            if(calHash(s, power, modulo, i, k) == hashValue)
                return s.substr(i, k);
        }
        return "";  // never returns this according to the constraints
    }
};
