
// Weekly Contest 273
// Dec 26
// NP P4 崩潰 QQ

/*
這題一開始我很單純的把值對應到 index 的 vector
針對每個 index 再去算值，於是就吃了 TLE
看了一下 input size，是 10^5，如果全部數字都一樣，跑的時間非常可觀
---
有絕對值還滿麻煩的，要判斷正、負
但如果從頭開始依序走到尾，對於 x[i]，可以找到所有等於 x[i] 且 index 小於 / 大於 i 的 index 總和
答案是
(i * 個數 - index 小於 i 的 index 總和) +
(index 大於 i 的 index 總和 - i * 個數) +
等於把絕對值裡面正、負拆開來
*/

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {

        long long n = arr.size();
        
        map<long long, long long> cnt;
        map<long long, long long> sum;
        
        vector<long long> smallSum(n, 0), smallCnt(n, 0);
        vector<long long> ans(n, 0);
        
        for(long long i = 0; i < arr.size(); i++) {
            
            smallSum[i] = sum[ arr[i] ];
            smallCnt[i] = cnt[ arr[i] ];
            
            cnt[ arr[i] ]++;
            sum[ arr[i] ] += i;
        }
        
        for(long long i = 0; i < arr.size(); i++) {
            ans[i] = i * smallCnt[i] - smallSum[i] + 
                     (sum[ arr[i] ] - smallSum[i]) - i * (cnt[ arr[i] ] - smallCnt[i]);
        }
        
        return ans;
    }
};

/*
Runtime: 632 ms, faster than 9.09% of C++ online submissions for Intervals Between Identical Elements.
Memory Usage: 124.4 MB, less than 100.00% of C++ online submissions for Intervals Between Identical Elements.
*/
