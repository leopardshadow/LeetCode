
// 2022.5.25

/*
這題一看就是 DP
---
首先會對長度排序，這樣就解決一維的問題，剩下寬度要解決
這裡有一個觀察：從小到大在放時，如果長度一樣，我會選擇寬度比較小的，這樣比較有可能再放下一個
所以一個長度只要留一個最小的寬度就好，這時候會得到一個一維陣列
現在問題就變成 longest increasing subsequence (LIS)
我原本是這樣想的，但後來發現邏輯是錯的，因為如果選小的，可能那個小的不夠大，不能再 +1
---
後來看了討論區，這個想法差不多是對的，上面邏輯錯誤的地方（選小的）改成排序時先依長度由小到大排序，長度一樣的話再用寬度由大到小，放進陣列找 LIS 就行
---
LIS 是 Leetcode 300. Longest Increasing Subsequence
有 O(n^2) 和 O(n log n) 的作法，O(n^2) 會 TLE ...
---
如果改成長寬可對調不知道怎麼寫 XD
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            if (a[0] == b[0])
                return a[1] > b[1];
            else
                return a[0] < b[0];
        });
        
        // LIS
        vector<int> lis;
        for(int i = 0; i < envelopes.size();i++){
            int e = envelopes[i][1];
            int idx = lower_bound(lis.begin(), lis.end(), e) - lis.begin();
            
            if(idx >= lis.size())
                lis.push_back(e);
            else
                lis[idx] = e;
        }
        
        return lis.size();
    }
};
/*
Runtime: 485 ms, faster than 53.21% of C++ online submissions for Russian Doll Envelopes.
Memory Usage: 77.6 MB, less than 70.83% of C++ online submissions for Russian Doll Envelopes.
*/
