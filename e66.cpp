/*
這樣居然是 100%，還以為除法要特別處理 @@
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if(carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
Memory Usage: 8.8 MB, less than 59.74% of C++ online submissions for Plus One.
*/
