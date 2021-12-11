// Biweekly Contest 67

/*
我一開始以某個點為中心，向左、向右找，遇到不符合條件的移動 center
雖然移動時不是 +1 慢慢移動，但這樣做還是用了許多多餘的計算
---
於是轉換想法，有點 dp 的想法：
dec[i] 存的是 i 往前有幾個 non-increasing 的元素
inc[i] 存的是 i 往後有幾個 non-decreasing 的元素
對於某位置 i，只有當 dec[i] 和 inc[i] 都足夠大的時候才把他加入 ans 的 vector
---
這樣做的 TC 是 O(n) + O(n) + O(n)，但是只有 16.67% QQ
---
如果把第 1 個和第 3 個迴圈合併可以省下一條 vector 的空間，不過賺了空間，犧牲的是可讀性，我比較喜歡現在這種寫法 XD
*/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
        vector<int> ans;
        
        int n = security.size();
        
        vector<int> inc(n, 1), dec(n, 1);

        for(int i = 1; i < n; i++) {
            if(security[i-1] >= security[i])
                dec[i] = dec[i-1] + 1;
        }
        for(int i = n - 2; i >= 0; i--) {
            if(security[i] <= security[i+1])
                inc[i] = inc[i+1] + 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(inc[i] > time && dec[i] > time)
                ans.push_back(i);
        }
        
        return ans;
    }
};

/*
Runtime: 173 ms, faster than 16.67% of C++ online submissions for Find Good Days to Rob the Bank.
Memory Usage: 89.5 MB, less than 16.67% of C++ online submissions for Find Good Days to Rob the Bank.
*/

// 應該是對的邏輯，但是會 TLE
// class Solution {
// public:
//     vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
//         vector<int> ans;
        
//         int center = time, i;
//         bool moveCenter;
        
//         while(center + time < security.size()) {
            
//             moveCenter = false;
//             for(i = 1; i <= time; i++) {
//                 if(security[center - i + 1] <= security[center - i]) {
                    
//                 }
//                 else {
//                     center = center - i + time + 1;
//                     moveCenter = true;
//                     break;
//                 }
//             }
            
//             if(moveCenter)
//                 continue;
            
//             for(int i = 1; i <= time; i++) {
//                 if(security[center + i - 1] <= security[center + i]) {
                    
//                 }
//                 else {
//                     center = center + i;
//                     moveCenter = true;
//                     break;
//                 }
//             }
            
//             if(!moveCenter) {
//                 ans.push_back(center);
//                 center++;
//             }
//         }
        
//         return ans;
//     }
// };
