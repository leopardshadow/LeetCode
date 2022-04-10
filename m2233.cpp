
// 2022.4.10
// Weekly Contest 288

/*
如果知道數學的規則，知道用 heap 就不難
但其實這個做法滿慢的，比較好的是用 map 合併一樣的數字
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  // min heap
        for (int n : nums)
            pq.push(n);
        for (int i = 0; i < k; i++) {
            int x = pq.top();
            pq.pop();
            x += 1;
            pq.push(x);
        }
        long long ans = 1;
        while (!pq.empty()) {
            ans = (ans * (long long)pq.top()) % 1000000007;
            pq.pop();
        }
        return ans;
    }
};
/*
Runtime: 752 ms, faster than 20.00% of C++ online submissions for Maximum Product After K Increments.
Memory Usage: 90.9 MB, less than 10.00% of C++ online submissions for Maximum Product After K Increments.
*/
