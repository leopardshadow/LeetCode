/*
Key. 先寫出式子
max(n) = max( max(n-1), max(n-2) + sum(n) )
max(n) - 到 n 為止最大的 earnings
sum(n) - 所有數字 n 的和
(這裡的 n 對應的是 nums[i])
---
從頭到尾沒看答案生出來的結果，速度超慢，只贏 8.04%
優化了一點點，現在到 10.06%，主要應該是差在往前跑那裡
*/

class Record {
public:
    int n, sum, maxV;
    Record(int n) {
        this->n = n;
        sum = n;
        maxV = 0;
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<Record> table;
        int ans = 0;
        table.push_back(Record(nums[0]));
        for(int i = 1; i < nums.size(); i++) {
            if(table.back().n == nums[i])
                table.back().sum += nums[i];
            else
                table.push_back(Record(nums[i]));
        }
        table[0].maxV = table[0].sum;
        
        if(table.size() == 1)
            return table[0].sum;
        
        if(table[1].n == table[0].n + 1)
            table[1].maxV = table[1].sum;     
        else 
            table[1].maxV = table[0].maxV + table[1].sum;
            
        ans = max(table[0].maxV, table[1].maxV);
        
        for(int i = 2; i < table.size(); i++) {
            
            int j;
            // if the previos is a neighbor number
            // we'll need to check. the previos one
            if(table[i].n == table[i-1].n + 1) {
                j = i - 2;
                while(j >= 0) {
                    table[i].maxV = max(table[i].maxV, table[j].maxV + table[i].sum);
                    j--;
                }
                ans = max(ans, table[i].maxV);
            }
            // otherwise, we can directly add 
            else {
                table[i].maxV = ans + table[i].sum;
                ans = table[i].maxV;
            }
        }
        return ans;
    }
};


/*
Runtime: 24 ms, faster than 10.06% of C++ online submissions for Delete and Earn.
Memory Usage: 9.4 MB, less than 71.46% of C++ online submissions for Delete and Earn.
*/
