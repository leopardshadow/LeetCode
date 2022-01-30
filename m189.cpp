
// 2022.1.30

/*
像這種題目滿有意思的，題目自己就說到這題有超多種做法
---
一開始的想法是拔掉尾巴，貼到頭去，重複好幾次這個動作，但貼到頭去需要移動整條 array，很花時間
所以雖然沒有用到額外的記憶體，但時間方面會超時
---
於是接下來決定先寫個能動的版本：用另一個 vector 來存
---
接下來是 O(1) extra space ˇ的版本
*/

// 這樣是 TLE!!! 應該是 insert begin 太花時間
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n;
//         for(int i = 0; i < k; i++) {
//             int x = nums.back();
//             nums.pop_back();
//             nums.insert(nums.begin(), x);
//         }
//     }
// };


// 花額外 O(n) 的空間來存
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(nums);
        nums.clear();
        for(int i = n - k; i < n; i++)
            nums.push_back(temp[i]);
        for(int i = 0; i < n - k; i++)
            nums.push_back(temp[i]);
    }
};
/*
Runtime: 50 ms, faster than 27.68% of C++ online submissions for Rotate Array.
Memory Usage: 25.5 MB, less than 39.37% of C++ online submissions for Rotate Array.
*/
