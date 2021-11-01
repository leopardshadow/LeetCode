/*
像這樣“連續”陣列怎樣的，看起來是 sliding window 的題目

先不用 sliding window 的概念，直觀來想
我把陣列每一個元素依序輪流當頭，往後計算它能到多長
這樣的方法是正確的，但他浪費了很多時間，會 TLE

我們浪費了什麼?
1. 不用每個都輪流當頭，舉例來說
    * 1 1 1 0 1 0 ...
    *   1 1 0 1 0 ...
    根本不用跑下面那組，因為頭往後移一個，但他尾巴能到的地方一樣，所以往後縮一個的那個一定比較少
2. 每次頭往後一格，計算往後能到哪裡時浪費了許多時間計算重複的東西

綜合上面兩點，我們可以引進 sliding windows 的概念

一開始 l = 0，我先讓 r 往後衝，看他能往後延伸到哪裡 (這裡有第一個長度)
接下來 l 往後移動直到找到 0，r 往後移動延伸 (繼續比較長度)
*/

// Sol 1 (TLE)
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
    
//         int l, r;
//         int curK;
//         int ans = -1;

//         for(l = 0; l < nums.size(); l++) {
//             r = l;
//             curK = k;
//             while(r < nums.size() && curK > 0) {
//                 if(nums[r] == 0)
//                     curK--;
//                 r++;
//             }
//             while(r < nums.size() && nums[r])
//                 r++;
//             ans = max(ans, r - l);
//         }
        
//         return ans;
//     }
// };



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    
        int l = 0, r = 0;
        int curK = k;
        int ans = -1;
        while(r < nums.size()) {
            
            while(r < nums.size() && curK > 0) {
                if(nums[r] == 0)
                    curK--;
                r++;
            }
            while(r < nums.size() && nums[r])
                r++;

            ans = max(ans, r - l);
            
            while(l < r && nums[l] == 1) {
                l++;
            }
            l++;
            curK ++;
            // r++;
        }
        return ans;
    }
};


/*
Runtime: 56 ms, faster than 70.85% of C++ online submissions for Max Consecutive Ones III.
Memory Usage: 55.5 MB, less than 63.43% of C++ online submissions for Max Consecutive Ones III.
*/