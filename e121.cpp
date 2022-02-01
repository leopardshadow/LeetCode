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




/*
看到 ptt C_and_CPP https://www.ptt.cc/man/C_and_CPP/D7F6/M.1309694493.A.E8A.html
這題用遞迴解要怎麼做
我用自己的方式寫的一個版本
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0).first;
    }
    // maxProfix, maxPrice
    pair<int, int> solve(vector<int>& prices, int i) {
        if(i == prices.size() - 1)
            return {0, prices[i]};
        else {
            pair<int, int> temp = solve(prices, i+1);
            return {max(temp.first, temp.second - prices[i]), max(temp.second, prices[i])};
        }
    }
};

/*
Runtime: 148 ms, faster than 30.84% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 121.4 MB, less than 5.97% of C++ online submissions for Best Time to Buy and Sell Stock.
*/

//***************************************************************************//
// DP D7

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, maxPrice = prices.back();
        for(int i = prices.size() - 2; i >= 0; i--) {
            ans = max(ans, maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        return ans;
    }
};

/*
Runtime: 124 ms, faster than 45.11% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.4 MB, less than 52.55% of C++ online submissions for Best Time to Buy and Sell Stock.
*/


//***************************************************************************//
// 2022.2.1
/*
印象中這是我寫 Leetcode 的第一題XD
之前好像都是從尾巴走，但從頭走的話 code 比較精簡!
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX, ans = 0;
        for(int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - minP);
            minP = min(minP, prices[i]);
        }
        return ans;
    }
};
/*
Runtime: 209 ms, faster than 30.38% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.3 MB, less than 90.32% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
