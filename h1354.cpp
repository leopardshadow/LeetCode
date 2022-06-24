
// 2022.6.24

// 應該是錯誤的邏輯
class Solution {
public:
    bool isPossible(vector<int>& target) {
        sort(target.begin(), target.end());
        int i = 0;
        while (i < target.size() && target[i] == 1)
            i++;
        int x = target.size();
        for ( ; i < target.size(); i++) {
            while (x < target[i])
                x = x - 1 + x;
            if (x == target[i])
                x = x - 1 + x;
            else if (x > target[i])
                return false;
        }
        return true;
    }
};

/*
好討厭 leetcode 的 example test case 都給很小...
然後 Daily 難度都亂跳
---
如果只看某一位，他是直接從 1 就跳到指定數值，還是會 1 -> x -> ... -> targer 慢慢來
---

這是題目的 Exampl1 1
[3,5,9]
---------------
[1,1,1] sum = 3
[3,1,1] sum = 5
[3,5,1] sum = 9
[3,5,9] sum = 17
---------------
這是一般的流程，倒過來想的話
最大的那個數字一定是最後設的

---

如果把它改一下
[3,5,10]
---------------
[1,1,1] sum = 3
[3,1,1] sum = 5
[3,5,1] sum = 9
[3,5,9] sum = 17
[3,5,17] Fail ...

[3,5,10] sum = 18
[3,5,1]  sum = 9 (拿掉的 10 != 9)
---------------

---

[5,8]
---------------
[1,1] sum = 2
[2,1] sum = 3
[3,1] sum = 4
[5,1]

[5,8] sum = 13
[5,1] sum = 6

---
會出現 mod，可以從這個 case 來感覺
[1,10]
像這種會出現很多重複的操作要想到 mod 可能可以加速
*/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        sort(target.begin(), target.end()); 
        long sum = std::accumulate(target.begin(), target.end(), 0l);
        priority_queue<int> pq(target.begin(), target.end());
        
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            sum -= x;

            if (x == 1 || sum == 1)
                return true;
            if (x < sum || sum <= 0 || x % sum == 0)
                return false;
            
            x %= sum;
            sum += x;
            pq.push(x);
        }
        return true;
    }
};
/*
Runtime: 85 ms, faster than 20.28% of C++ online submissions for Construct Target Array With Multiple Sums.
Memory Usage: 28.7 MB, less than 72.03% of C++ online submissions for Construct Target Array With Multiple Sums.
*/
