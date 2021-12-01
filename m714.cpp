// DP D8

/*
寫完 309. Best Time to Buy and Sell Stock with Cooldown 這題之後，寫這題滿有感覺的
只要把 fee 減掉的部分放在加 profits 那邊就好

話說這樣如果考個 cooldown + transaction fee 也可以~

bought[i] 表示買了第 i 天結束時，手上「有」股票
sold[i] 則表示買了第 i 天結束時，手上「沒有」股票
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



//***************************************************************************//
// 2021.12.1 before G VO

/*
用三個狀態寫完 309. Best Time to Buy and Sell Stock with Cooldown 後
來試試有 transaction fee 的，原始狀態參考那題
現在不用休息，只剩兩個狀態: s0 和 s2 合併成 s0
---
不過在寫這題時想到，如果現在休息幾天改成用參數傳入，狀態的寫法變得很麻煩，因為我們不知道要弄成幾個狀態
如果 3 天，就會有： 剛賣完第一天 --> 賣完第二天 --> 賣完第三天 --> 終於可以買了
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<int> s0(prices.size()),
                    s1(prices.size());
        s0[0] = 0;
        s1[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            s0[i] = max(s0[i-1], s1[i-1] + prices[i] - fee);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
        }
        return s0.back();;
    }
};
