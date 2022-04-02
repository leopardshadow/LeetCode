
// Biweekly Contest 75

/*
就只是算 bit 有幾位不同
*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int ans = 0;
        while (diff) {
            ans ++;
            diff = diff & (diff - 1);
        }
        return ans;
    }
};
