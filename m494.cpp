/*
這題的 tag 是 backtracking 和 DP，但我用了個奇怪的解法
沒有用到 DP
每個數字有正負號，所以窮舉所有可能是 2^n，而全部走過加起來又會耗 n 的時間，我想要縮短這些時間
因為我們每次都是每個都取 (差別只有正負號)，如果兩個列舉出來的可能只差一項正改負或負改正，就不用全部重算了
所以這裡在產生所有可能時不適用 0 1 2 3 ... 的順序，
而是採用 Grey code 的順序，這樣一來，我們能夠枚舉所有可能，又可以讓相鄰只差 1
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int gen;
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(target == sum)
            ans++;
        
        int val = 0, newval, diff, idx;
        
        for (int i = 1; i < (1 << nums.size()); i++) {

            newval = (i ^ (i >> 1));
            diff = val ^ newval;
            
            idx = (int)log2(diff);
            
            // e.g. 00 => a0 + a1
            //   -> 01 => a0 - a1
            // diff 01.    - 2 a1
            if(newval > val) {
                sum -= 2 * nums[idx];
            }
            // e.g. 11 => - a0 - a1
            //   -> 10 => - a0 + a1
            // diff 01       + 2 a1
            else { // newval < val
                sum += 2 * nums[idx];
            }
            
            if(sum == target)
                ans++;
            
            val = newval;
        }
        return ans;
    }
};

/*
Runtime: 1300 ms, faster than 12.42% of C++ online submissions for Target Sum.
Memory Usage: 9.2 MB, less than 57.34% of C++ online submissions for Target Sum.
*/
