/*
Nice solution at the bottom
*/

/*
Record the fewest number of coins to make i 
*/

/*
1 2 5 (11)  -> 3
0 1 2 3 4 5 6 7 8 9 10 11
X 1 1     1                          
X 1 1 2 3 1 2 2 3 3  2  3             
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // arr stores the fewest number of coins for every amount 
        int *arr = new int [amount + 1];
        
        // fail for the test case
        // [1]
        // 0
        // Be careful when using amount to initialze the array
        // do boundary checking!!
        arr[0] = 0;
        
        //
        for(int i = 0; i < coins.size(); i++) {
            if(amount >= coins[i])
                arr[coins[i]] = 1;
        }
        
        // iterate to generate arr
        for(int i = 1; i <= amount; i++) {
            
            if(arr[i] > 0)
                continue;
            
            int minCnt = 9999999;
            // tries every coins
            for(int j = 0; j < coins.size(); j++) {
                if (i - coins[j] > 0 && arr[i - coins[j]] > 0)
                    minCnt = minCnt > arr[i - coins[j]] ? arr[i - coins[j]] : minCnt;
            }
            arr[i] = minCnt + 1;
        }
        
        int ans = arr[amount];
        delete []arr;
        return ans >= 9999999 ? -1 : ans;
    }
};

/*
Runtime: 80 ms, faster than 65.95% of C++ online submissions for Coin Change.
Memory Usage: 14.4 MB, less than 65.97% of C++ online submissions for Coin Change.
*/



/*
11 = 1 + 10
   = 2 +  9
   = 5 +  6
*/
class Solution {
private:
    vector<int> coins;
    int *arr;
public:
    int coinChange(vector<int>& coins, int amount) {
        arr = new int [amount+1];
        for(int i = 0; i < coins.size(); i++) {
            if(amount >= coins[i])
                arr[coins[i]] = 1;
        }
            
        
        this->coins = coins;
        int ans = change(amount);
        delete []arr;
        return ans >= 999999 ? -1 : ans;
    }
    
    int change(int amount) {
        // for(int i = 0; i < coins.size(); i++) {
        //     if(amount == coins[i])
        //         return 1;
        // }

        
        if(amount == 0)
            return 0;
        
        if(amount < 0)
            return 999999;
        
        if(arr[amount] > 0) {
            return arr[amount];
        }

        
        int minCnt = 999999;
        // iterate through every coins
        for(int i = 0; i < coins.size() ; i++) {
           minCnt = min(minCnt, change(amount - coins[i]));
        }
        minCnt += 1;
        arr[amount] = minCnt;
        return minCnt;
    }
};

/*
TLE without memoization
*/
/*
Runtime: 72 ms, faster than 72.33% of C++ online submissions for Coin Change.
Memory Usage: 15 MB, less than 23.86% of C++ online submissions for Coin Change.
*/


//***************************************************************************//
// Review: 2021.11.29 before G VO


/*
其實就是背包問題的變形
認真看了背包問題題型之後，有種豁然開朗的感覺 XDD
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int c : coins) {
            for(int i = c; i <= amount; i++) {
                if(dp[i - c] != INT_MAX) // need this if, otherwise integer overflow
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};
