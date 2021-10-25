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
        
        //
        for(int i = 0; i < coins.size(); i++) {
            arr[i] = 1;
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