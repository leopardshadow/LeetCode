/*
Note. 
因為可以在當天買賣
所以只要賣的價格高於買的價格，就立即賣，獲利加到總和
不論今日價格為何，在做完上一步後，buyPrice = 今天的 price
 - 如果後面遇到更高的價格，就出現了當天買賣 (e.g. 1 3 6，1-3 產生一次獲利，3-6 也是一次獲利，也可以合併來看 1-6)
 - 如果後面的價格比較低，價格被洗掉 (e.g. 1 5 2 X，1-5 有一次獲利，再來就是 2-?)

如果改成不能當天買賣應該也沒差，反正在寫程式時邏輯感覺是當天買賣，但是也可以看成合併
有 cool-down (309) 或是限制買賣次數 (123) 的比較麻煩
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
                        
        int buyPrice = prices[0], curProfit;
        
        for(int i = 1; i < prices.size(); i++) {
            
            // donot sell
            if(prices[i] <= buyPrice) {
                buyPrice = prices[i];
            }
            // sell leads to a postive profit
            else {
                curProfit = prices[i] - buyPrice;
                maxProfit += curProfit;
                buyPrice = prices[i];
            }
        }
        
        return maxProfit;
    }
};