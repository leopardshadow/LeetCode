
// Biweekly Contest 74 (2022.3.19)

/*
嗚嗚嗚 我在耍笨
一開始用 xor 解，但這樣邏輯是錯的，3 可以由 1 xor 2 得來，但他們不能組成 pair
居然在 easy 吃了兩個 WA，寫得太急了，欲速則不達，下次要小心一點 QQ
*/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> m;
        for(int n : nums)
            m[n]++;
        for(auto it : m)
            if(it.second % 2 != 0)
                return false;
        return true;
    }
};
/*
Runtime: 29 ms, faster than 38.46% of C++ online submissions for Divide Array Into Equal Pairs.
Memory Usage: 14.8 MB, less than 7.69% of C++ online submissions for Divide Array Into Equal Pairs.
*/
