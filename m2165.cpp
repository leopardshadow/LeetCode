
// Leetcode 某週競賽題

/*
greedy
*/

class Solution {
public:
    long long smallestNumber(long long num) {
        
        int cnts[10] = { 0 };
        
        bool positive = true;
        if(num < 0) {
            positive = false;
            num = -num;
        }
        
        while(num) {
            cnts[num % 10]++;
            num /= 10;
        }
        
        long long ans = 0;
        // find the smallest
        if(positive) {
            // one non-zero smallest number
            for(int i = 1; i <= 9; i++) {
                if(cnts[i]) {
                    ans = ans * 10 + i;
                    cnts[i]--;
                    break;
                }   
            }
            // and other numbers
            for(int i = 0; i <= 9; i++) {
                while(cnts[i]) {
                    ans = ans * 10 + i;
                    cnts[i]--;
                }
            }
        }
        // find the biggest 
        else {
            for(int i = 9; i >= 0; i--) {
                while(cnts[i]) {
                    ans = ans * 10 + i;
                    cnts[i]--;
                }
            }
            ans = -ans;
        }
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Value of the Rearranged Number.
Memory Usage: 5.9 MB, less than 89.22% of C++ online submissions for Smallest Value of the Rearranged Number.
*/
