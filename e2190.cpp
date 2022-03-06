
// 2022.3.6
// Biweekly Contest 73

/*
這題難的是題目好長 (?)
target 在句子中出現的時機點好怪XD
*/

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> m;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == key)
                m[nums[i+1]]++;
        }
        int ans, cnt = -1;
        for(const auto &p : m) {
            if(p.second > cnt) {
                cnt = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 91.67% of C++ online submissions for Most Frequent Number Following Key In an Array.
Memory Usage: 12.6 MB, less than 8.33% of C++ online submissions for Most Frequent Number Following Key In an Array.
*/
