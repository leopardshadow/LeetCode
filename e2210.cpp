
// Weekly Contest 285 (2022.3.20)

/*
昨天 easy 題 WA 了兩次，讓我今天寫這題 east 時超小心 QQ
*/

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> ns;
        for(int i = 0; i < nums.size(); i++) {
            if(ns.size() && ns.back() == nums[i])
                ;
            else
                ns.push_back(nums[i]);
        }
        int ans = 0;
        for(int i = 1; i < ns.size() - 1; i++) {
            if((ns[i] > ns[i+1] && ns[i] > ns[i-1]) ||
               (ns[i] < ns[i+1] && ns[i] < ns[i-1]))
                ans++;
        }
        return ans;
    }
};
/*
Runtime: 6 ms, faster than 72.73% of C++ online submissions for Count Hills and Valleys in an Array.
Memory Usage: 8.9 MB, less than 18.18% of C++ online submissions for Count Hills and Valleys in an Array.
*/
