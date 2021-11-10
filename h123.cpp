
/*
WA case: [1,2,4,2,5,7,2,4,9,0]
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> profits;
        // for handling prices.length too short
        profits.push_back(0);
        profits.push_back(0);
        
        int maxProfit = 0;
                        
        int buyPrice = prices[0], lastSellDay = 0, lastBuyDay;
        int curProfit;
        
        for(int i = 1; i < prices.size(); i++) {
            
            if(prices[i] <= buyPrice) {
                buyPrice = prices[i];
                lastBuyDay = i;
            }
            // sell leads to a postive profit
            else {
                curProfit = prices[i] - buyPrice;
                if(lastSellDay == lastBuyDay)
                    profits.back() += curProfit;
                else
                    profits.push_back(curProfit);
                buyPrice = prices[i];
                lastSellDay = i;
                lastBuyDay = i;
            }
        }
        sort(profits.rbegin(), profits.rend());
        
        return profits[0] + profits[1];
    }
};