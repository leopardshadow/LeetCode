
// 2022.4.7

/*
就照著題目說的做，拿出兩個最大的弄在一起，放回去，直到剩下零個或一個
---
我原本的寫法是 pq 宣告後，for 迴圈把 stone 慢慢 push 進去，改成宣告時同時給他值，速度從 7ms (12.87%) 飆升到 0ms (100%) OAO
---
這題是 easy 的雲音應該是他把如何做都直接寫進題目裡了：要取 2 個最重的弄在一起
但為什麼這樣的策略會讓最後剩下來的最小呢？
1, 2 的情況很單純，從 3 個的開始看
c > b > a，有兩種弄法
 (1) (c b) a
 (2) c (b a)
(1) 會比 (2) 好，原因是 (b - a) 和 c 的差距又變大了 
| c - b - a | vs. c - b + a，(c - b) 大家都有，且都是正的，一個是加上 a 拉大差距，另一個則是減掉 a，雖然可能減太多變成負的要用絕對值拉回來，但是會比較小

應該可以推到 4 個、5 個 ... 嗎？？？
*** 更新：這題照著做就好，general 的 case 會用到 DP，是下面那題 ***
---
這題的變形是 [1049. Last Stone Weight II
](https://leetcode.com/problems/last-stone-weight-ii/)，會用到 DP
之前居然寫過，再看時居然沒印象 QQ
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int s1, s2;
        while (pq.size() > 1) {
            s1 = pq.top();
            pq.pop();
            s2 = pq.top();
            pq.pop();
            if (s1 != s2)
                pq.push(s1 - s2);
        }
        return pq.size() ? pq.top() : 0;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
Memory Usage: 7.5 MB, less than 97.59% of C++ online submissions for Last Stone Weight.
*/
