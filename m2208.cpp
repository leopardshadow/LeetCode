
// Biweekly Contest 74 (2022.3.19)

/*
這次 contest 對我來說最簡單的一題
完全沒有 WA，而且一臉就是「我是 heap」的樣子 XD
*/

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0, target = 0;
        for(int n : nums) {
            sum += (double)n;
            pq.push((double)n);
        }
        target = sum / 2;
        int ans = 0;
        while(sum > target) {
            double x = pq.top();
            pq.pop();
            x /= 2;
            sum -= x;
            pq.push(x);
            ans++;
        }
        return ans;
    }
};
