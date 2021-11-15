/*
Copyright 2021 Cheng-Cheng Lo
*/

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0;
    int highestPrice = 0;
    int profit;
    for (int i = pricesSize - 1; i >= 0; i--) {
        highestPrice = (highestPrice > prices[i] ? highestPrice : prices[i]);
        profit = highestPrice - prices[i];
        max_profit = (max_profit > profit ? max_profit : profit);
    }
    return max_profit;
}

// int main() {

//     int example1[] = {7,1,5,3,6,4};
//     printf("example1: %d\n", mmaxProfit(example1, 6));

//     int example2[] = {7,6,4,3,1};
//     printf("example2: %d\n", mmaxProfit(example2, 5));

//     return 0;
// }



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int maxPrice = prices.back();
        for(int i = prices.size() - 2; i >= 0; i--) {
            maxProfit = max(maxPrice - prices[i], maxProfit);
            maxPrice = max(maxPrice, prices[i]);
        }
        return maxProfit;
    }
};

/*
Runtime: 128 ms, faster than 41.81% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.4 MB, less than 52.43% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
