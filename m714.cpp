// DP D8

/*
寫完 309. Best Time to Buy and Sell Stock with Cooldown 這題之後，寫這題滿有感覺的
只要把 fee 減掉的部分放在加 profits 那邊就好

話說這樣如果考個 cooldown + transaction fee 也可以~
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1)
            return 0;
        vector<int> bought(prices.size(), 0) ;
        vector<int> sold(prices.size(), 0);
        bought[0] = -prices[0];
        bought[1] = max(-prices[0], -prices[1]);
        sold[1] = max(0, prices[1] - prices[0] - fee);
        int ans = sold[1];
        for(int i = 2; i < prices.size(); i++) {
            bought[i] = max(bought[i-1], sold[i-1] - prices[i]);
            sold[i] = max(sold[i-1], bought[i-1] + prices[i] - fee);
            ans = max(ans, sold[i]);
        }
        return ans;
    }
};

/*
Runtime: 96 ms, faster than 65.40% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
Memory Usage: 59.8 MB, less than 26.03% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
*/
