// Weekly Contest 271

/*
在 contest 結束後才寫出來
---
原本想用 DP 解，用二維的，一維存 k，一維存在哪裡，但這樣用到的記憶體會超多，而且狀態轉移感覺也很麻煩
contest 結束後看到這題的 tag 是 sliding window 後就有想法了
雖然有想法，但把它實現的過程中還是花了不少心力，畢竟是 hard
---
這個題目有以下幾個特點：
* 最多折返一次 (i.e 0 或 1 次)，多的折返都是在浪費步數，當然如果 k 很大就沒差
* 如果從 a 到 b，中間所有的水果都會被採收 --> 所以**只在乎頭、尾**，因為中間會全收
---
原本不想建出一整條，想用原先給的 vector of pair of int 做，但有點麻煩，先寫了建一整條的
---
注意這裡的 l 和 r，特別是和 startPos +-1 的地方..
*/

class Solution {
    int startPos;
    int calK(int l, int r) {
        
        int dl = startPos - l;
        int dr = r - startPos;
        return 2 * min(dl, dr) + max(dl, dr);
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
                
        this->startPos = startPos;
        
        vector<int> table(max(fruits.back()[0], startPos) + 2, 0);
        for(auto fruit : fruits)
            table[fruit[0]] = fruit[1];
        
        int ans = table[startPos];
        int l = startPos, r = startPos;
        int cur = table[startPos];
            
        while(l >= 1 && calK(l - 1, r) <= k) {
            l--;
            cur += table[l];
            ans = max(ans, cur);
        }
        
        while(l <= startPos && r < fruits.back()[0]) {
            
            r++;
            cur += table[r];
            while(l <= startPos && calK(l, r) > k) {
                cur -= table[l];
                l++;
            } 
            if(l <= startPos && calK(l, r) <= k) {
                ans = max(ans, cur);
            }
        }
                
        return ans;
    }
    
};


/*
Runtime: 444 ms, faster than 58.33% of C++ online submissions for Maximum Fruits Harvested After at Most K Steps.
Memory Usage: 167.5 MB, less than 25.00% of C++ online submissions for Maximum Fruits Harvested After at Most K Steps.
*/

// class Solution {
// public:
//     int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
//         int startIdx = -1;
        
//         // find the corresponding index for startPos
//         // can be accelerated by binary search
//         if(startPos > fruits.back()[0]) {
//             fruits.push_back({startPos, 0});
//             startIdx = fruits.size();
//         }
            
//         for(int i = fruits.size() - 1; i >= 0; i--) {
//             if(fruits[i][0] == startPos) {
//                 startIdx = i;
//                 break;
//             }
//             else if(fruits[i][0] < startPos) {
//                 fruits.insert(fruits.begin() + i + 1, {startPos, 0});
//                 startIdx = i + 1;
//                 break;
//             }
//         }
//         if(startIdx == -1) {
//             startIdx = 0;
//             fruits.insert(fruits.begin(), {startPos, 0});
//         }
            
        
//         // left index & right index
//         int l = startIdx - 1, r = startIdx;
        
//         int harvested = fruits[startIdx][1];
//         int ans = harvested;
        
//         // push to the leftmost
//         while(l >= 0 && startPos - fruits[l][0] <= k) {
                        
//             harvested += fruits[l][1];
//             ans = max(ans, harvested);
//             l--;
//         }
        
        
//         while(r + 1 < fruits.size() && l + 1 <= startIdx) {

//             int dl, dr, dis;
//             dl = startPos - fruits[l][0];
//             dr = fruits[r][0] - startPos;
//             dis = 2 * min(dl, dr) + max(dl, dr);

//             if(dis > k) {
//                 harvested -= fruits[l][1];
//                 l++;
//                 continue;
//             }
//             else {
//                 harvested += fruits[r][1];
//                 r++;
//                 dl = startPos - fruits[l][0];
//                 dr = fruits[r][0] - startPos;
//                 dis = 2 * min(dl, dr) + max(dl, dr);
//                 if(dis <= k)
//                     ans = max(ans, harvested);
//             }
//         }
        
//         return ans;
//     }
// };
