
// 2021.12.26

/*
這題之前看過但沒特別去寫他，daily 就遇到了
---
出現 top K 或 K closest 這類關鍵字可以用 heap 解
也常常和 pair 搭配，前面放用來比較的值，後面放資料本身 ; 不用的話在 comparator 當場算也行
---
題目要求的是 K closest，可以用 "max" heap 來存東西
如果超過指定 size 的，會從「最大」的開始拔
---
發現常常搞不清楚 min heap 和 max heap
min heap 的最小值在 root，而 max heap 是最大值在 root
從 heap pop 出東西時會把 root 拔掉 (所以 max heap 就是拔最大值)
拔完後重新整理讓他再次成為合法的 heap
---
comp (lhs, rhs)
max heap 的 **rhs** 要比較大，i.e. lhs < rhs (less)
min heap 的 **rhs** 要比較小，i.e. lhs > rhs (greater)
!!!都用右手邊去比!!!
---
STL priority queue 預設的是 max heap，如果想用 min heap 可以用 greater<T>
看要排序什麼，可以是 greater<int>, greater<double> 之類的
---
sort 也可以用 greater，不過如果只是要反著排，我會把
sort(arr.begin(), arr.end()) 改成
sort(arr.rbegin(), arr.rend())
*/

struct comp {
    bool operator()(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) const{
        return a.first < b.first;
    }
};

class Solution {
    int square(int x) {
        return x * x;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, comp> pq;
        
        for(auto p : points) {
            int d = square(p[0]) + square(p[1]);
            pq.push({d, p});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

/*
Runtime: 280 ms, faster than 27.39% of C++ online submissions for K Closest Points to Origin.
Memory Usage: 67.5 MB, less than 23.13% of C++ online submissions for K Closest Points to Origin.
*/
