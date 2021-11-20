/*
Key. 先寫出式子
max(n) = max( max(n-1), max(n-2) + sum(n) )
max(n) - 到 n 為止最大的 earnings
sum(n) - 所有數字 n 的和
(這裡的 n 對應的是 nums[i])
---
從頭到尾沒看答案生出來的結果，速度超慢，只贏 8.04%
優化了一點點，現在到 10.06%，主要應該是差在往前跑那裡
最後參考了別人的解答，才弄到 93.64%
*/

class Record {
public:
    int n, sum, maxV;
    Record(int n) {
        this->n = n;
        sum = n;
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
        int dp1, dp2;
        
        dp1 = table[0].sum;
        
        if(table.size() == 1)
            return table[0].sum;
        
        if(table[1].n == table[0].n + 1)
            dp2 = table[1].sum;     
        else 
            dp2 = dp1 + table[1].sum;
            
        ans = max(dp1, dp2);
        
        for(int i = 2; i < table.size(); i++) {
            
            int j;
            // if the previos is a neighbor number
            // we'll need to check. the previos one
            if(table[i].n == table[i-1].n + 1) {
                ans = max(dp2, dp1 + table[i].sum);
            }
            // otherwise, we can directly add 
            else {
                ans = ans + table[i].sum;
            }
            dp1 = max(dp1, dp2);
            dp2 = ans;
        }
        return ans;
    }
};


/*
Runtime: 4 ms, faster than 93.64% of C++ online submissions for Delete and Earn.
Memory Usage: 9.5 MB, less than 71.46% of C++ online submissions for Delete and Earn.
*/

// DP D3
// 基本上 DP 的題目寫完狀態轉移的式子差不多就結束惹
/*
這題大致的想法是
我先把出現的數字和他造成的和統計一下，依 key value 排序
接著，對於 i 位置，如果
(1) 他是前一個數字加一，則我們不能都取，所以選 往前兩個最大的 + i 位的和 和 往前一個最大的，兩者間取 max
(2) 如果不是，那就代表這個數字和前一格數字可以都取就加起來
(1) / (2) 對應的就是迴圈中的 if / else 
*/ 
/*** 下面這個寫法應該比較符合我的直觀w ***/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map <int, int> ma;
        for(int n : nums)
            ma[n] += n;
        
        vector< pair<int, int> > m;
        
        for(unordered_map <int, int>::iterator it = ma.begin(); it != ma.end(); it++)
            m.push_back({it->first, it->second});
        sort(m.begin(), m.end());    
        
        int dp2 = m[0].second,
            dp1,
            dp;

        if(m.size() == 1)
            return m[0].second;
        
        if(m[0].first + 1 == m[1].first)
            dp1 = max(m[0].second, m[1].second);
        else
            dp1 = m[0].second + m[1].second;
        
        if(m.size() == 2) {
            return dp1;
        }
        for(int i = 2; i < m.size(); i++) {
            if(m[i-1].first + 1 == m[i].first)
                dp = max(dp1, 
                         dp2 + m[i].second);
            else
                dp = dp1 + m[i].second;
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};

/*
Runtime: 4 ms, faster than 93.60% of C++ online submissions for Delete and Earn.
Memory Usage: 10 MB, less than 55.19% of C++ online submissions for Delete and Earn.
*/
