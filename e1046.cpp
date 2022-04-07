
// 2022.4.7

/*
就照著題目說的做，拿出兩個最大的弄在一起，放回去，直到剩下零個或一個
---
我原本的寫法是 pq 宣告後，for 迴圈把 stone 慢慢 push 進去，改成宣告時同時給他值，速度從 7ms (12.87%) 飆升到 0ms (100%) OAO
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
