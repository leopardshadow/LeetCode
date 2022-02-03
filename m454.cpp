
// 2022.2.3

/*
Key. 把時間複雜度相乘的運算弄成相加的
從最直接的暴力解 O(n^4) 降到 O(n^3)，最後再降成 O(n^2)!
*/

// O(n^3) 會 TLE
// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
//         unordered_map<int, int> m1, m2, m3, m4;
        
//         for(const int &n : nums1)
//             m1[n]++;
//         for(const int &n : nums2)
//             m2[n]++;
//         for(const int &n : nums3)
//             m3[n]++;
//         for(const int &n : nums4)
//             m4[n]++;

//         int ans = 0, cnt;
//         for(const auto &it1 : m1) {
//             for(const auto &it2 : m2) {
//                 for(const auto &it3 : m3) {
//                     int tar = -it1.first -it2.first - it3.first;
//                         ans += m4[tar] * it1.second * it2.second * it3.second;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int, int> m;
        for(const int &n1 : nums1)
            for(const int &n2 : nums2)
                m[- n1 - n2]++;
        
        for(const int &n3 : nums3)
            for(const int &n4 : nums4)
                ans += m[n3 + n4];

        return ans;
    }
};

/*
Runtime: 341 ms, faster than 40.99% of C++ online submissions for 4Sum II.
Memory Usage: 24.6 MB, less than 36.00% of C++ online submissions for 4Sum II.
*/
