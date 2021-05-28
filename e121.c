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
