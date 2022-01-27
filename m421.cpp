
// 2022.1.27

/*
一開始還以為這個 index 可以很多，如果是的話，可能要被歸在 hard (?)
---
最簡單的做法當然就是 (i, j) 組合全部跑過一次，但從他輸入的 size 來看可能會超時
---
這題的 tag 是 trie，超酷的
---
Note. bitset 的用法
*/

/*
這是我原本的想法，pass 38 / 41 test cases，有夠難 debug @@
但我又不想用 trie 這種我覺得這題在面試想不出來的東西
---
反例 QQ 
1111..1,
1010..0,
 100..0,
      1
*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> nbit(32);
        
        vector<int> mask(32, 0);
        int temp = 0;
        for(int i = 0; i < 32; i++) {
            temp = (temp << 1) | 1;
            mask[i] = ~temp;
        }
            
        for(int i = 0; i < 32; i++) {
            for(const int &n : nums) {
                if((n & (1 << i)) && ((n & (mask[i])) == 0))
                    nbit[i].push_back(n);
            }
        }
        int msb = 31;
        while(msb >= 0 && nbit[msb].size() == 0)
            msb--;
        
        int ans = 0;
        
        if(nums[0] == 0 && msb >= 0) {
            for(const int &n : nbit[msb])
                ans = max(ans, n);
        }
        
        for(const int &nj : nbit[msb]) {
            for(const int &ni : nbit[msb]) {
                ans = max(ans, ni ^ nj);
            }
        }
        
        int mi, mj;

        for(int nb = msb - 1; nb >= 0; nb--) {
            int stop = 0;
            for(const int &nj : nbit[msb]) {
                for(const int &ni : nbit[nb]) {
                    if(ni ^ nj > ans) {
                        ans = ni ^ nj;
                        mi = ni;
                        mj = nj;
                    }
                    
                    stop = stop | ( ((ni & (1 << nb)) > 0) && ((nj & (1 << nb)) == 0));
                }
            }
            
            // if(stop)
            //     break;
        }
        cout << mi << " " << mj;
        return ans;
    }
};
