
/*
其實在寫這題時，知道他的想法很簡單，但不知道怎樣寫比較漂亮
---
如果有一個 char 出現得特別多，那就把它交錯擺就行
如果大家出現頻率都差不多，那也一定可以找到擺法
---
因為要交錯擺，所以我是以
0, 2, 4, 6, ...
1, 3, 5, 7, ...
這樣的順序放

從最常出現的 char 先，再來是第二常出現的 (heap!!) 以此類推

如果有人放到是後面的 (例如全部是 0..19，他佔 16 18)
剛好跨越奇數、偶數，接下來在擺時會從 0 2 4 開始放
前面已經檢查過可以放得下，這樣的擺法不會讓相同 char 出現在隔壁
---
在寫的時候遇到一個小問題：
C++ priority_queue 的 top 是回傳 constant reference，不能亂改值
(這聽起來也是滿合理的，因為改了值可能會造成整棵 heap 變化)
---
如果這題改成 rearrange 需要成本 (固定成本 or 依距離調整)
要回傳成本最少的 reorganize 之後的 string 感覺超級麻煩欸
*/


class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int cnt[26] = { 0 };
        for(char c : s)
            cnt[c - 'a']++;

        // max heap
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < 26; i++) {
            if(cnt[i])
                pq.push({cnt[i], i});
        }
        
        auto curr = pq.top();
        if(curr.first > (n + 1) / 2)
            return "";
        pq.pop();
                
        for(int i = 0; i < s.length(); i += 2) {
            if(curr.first == 0) {
                curr = pq.top();
                pq.pop();
            }
            curr.first--;
            s[i] = 'a' + curr.second;
        }
        for(int i = 1; i < s.length(); i += 2) {   
            if(curr.first == 0) {
                curr = pq.top();
                pq.pop();
            }
            curr.first--;
            s[i] = 'a' + curr.second;
        }

        return s;
    }
};

// Ya!!! 是 100.00% faster
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reorganize String.
Memory Usage: 6.2 MB, less than 88.06% of C++ online submissions for Reorganize String.
*/
