
// DP D8

/*
Hint. FSM / DFA
             ┌───┐
             |   |
             |   ▼
  buy       .───────.                  
 ┌───────▶ (   hold  )                 
 |          `──────┬'    sell              
 |            |    └───────┐            
 |    ┌───────┘            │           
 |    ▼   nop              ▼           
 .───────.            .───────.  ────────┐
(  rest   )          (  sold   )         |  nop
 `───────'            `───────'  ◀───────┘  
     ▲                    │           
     │                    │           
     └────────────────────┘           
        nop (cooldown
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ (有畫錯)        
3 種狀態 --> 可以直接用 3 個儲存的表格


在討論區也有看到用 2 種狀態的作法，但 i 就不只和 i - 1 相關，而也會和 i - 2 有關

在 Neetcode Youtube 頻道裡也看到一種很有趣的作法，本質上和上面兩個狀態的作法一樣，但他不用陣列去存，而是把 (i / buy/sell) 當成 key，對應到 profit
想練習他的作法，從 python 翻成 C++ 結果寫成 `if:` 也少分號和 int wwwwww
不過空間和時間的效率沒有很好

我比較喜歡第二種作法，兩個狀態的

這裡的狀態表示如果 i 處在那個狀態，當前的最大 profits 是多少

```cpp
    bought[0] = -prices[0];  // 如果買了 0，利潤就減少了
    bought[1] = max(-prices[0], -prices[1]);  // 從 0, 1 取便宜的買
    sold[1] = max(0, prices[1] - prices[0]);  // 如果 1 比 0 高價，就會賺取利潤
    ans = sold[1]; 
    // base case 是  size <= 2
    for(int i = 2; i < prices.size(); i++) {
        // 如果 i 要處於買了/持有股票的狀態，可以從 i-1 就買了，或是從 i-2 的狀態的利潤扣錢來買
        bought[i] = max(bought[i-1], sold[i-2] - prices[i]);
        // 如果 i 要處於賣了/沒有股票的狀態，可以從 i-1 就是沒有股票的狀態來，或是從 i-1 持有股票的狀態來賣，加上利潤
        sold[i] = max(sold[i-1], bought[i-1] + prices[i]);
        // sold[i] 一定比 bought[i] 大 (因為買了扣錢而不賣掉賺錢，利潤一定比較少
        ans = max(ans, sold[i]);
    }
    return ans;
```

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        
        // these tables record max profit of i being state ____
        vector<int> rest(n, 0);
        vector<int> sold(n, 0);
        vector<int> bought(n, 0);
        bought[0] = -prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            bought[i] = max(rest[i-1] - prices[i], bought[i-1]);
            sold[i] = bought[i-1] + prices[i];
            rest[i] = max(max(bought[i-1], sold[i-1]), rest[i-1]);
            ans = max(sold[i], rest[i]);
        }
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 32.88% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 11.2 MB, less than 47.12% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
*/

//***************************************************************************//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int ans = 0;
        vector<int> bought(prices.size(), 0);
        vector<int> sold(prices.size(), 0);
        bought[0] = -prices[0];
        bought[1] = max(-prices[0], -prices[1]);  // buy the cheaper one from 0 & 1
        sold[1] = max(0, prices[1] - prices[0]);  // if buy 0 and sell 1 make profits
        ans = sold[1];
        for(int i = 2; i < prices.size(); i++) {
            bought[i] = max(bought[i-1], sold[i-2] - prices[i]);
            sold[i] = max(sold[i-1], bought[i-1] + prices[i]);
            ans = max(ans, sold[i]);
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 11.2 MB, less than 79.72% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
*/

//***************************************************************************//
class Solution {
    vector<int> prices;
    map<pair<int, bool>, int> dp;
public:
    int dfs(int i, bool buying) {
        if(i >= prices.size())
            return 0;
        if(dp.find({i, buying}) != dp.end())
            return dp[{i, buying}];
        if(buying) {
            int buy = dfs(i+1, !buying) - prices[i];
            int cooldown = dfs(i+1, buying);
            dp[{i, buying}] = max(buy, cooldown);
        }
        else {
            int sell = dfs(i+2, !buying) + prices[i];
            int cooldown = dfs(i+1, buying);
            dp[{i, buying}] = max(sell, cooldown);
        }
        return dp[{i, buying}];
    }
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        return dfs(0, true);
    }
};

/*
Runtime: 17 ms, faster than 15.63% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 13.6 MB, less than 5.13% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
*/
