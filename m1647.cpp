
// 2022.6.28

/*
一開始 size 判斷寫 == 0，但是在迴圈裡有和下一個比較，所以是 > 1
注意 size 大小範圍RRR
*/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for (const char &c : s)
            cnt[c - 'a']++;
        priority_queue<int> pq(cnt.begin(), cnt.end());
        int ans = 0;
        while (pq.size() > 1) {
            
            int x = pq.top();
            pq.pop();
            
            while (pq.top() == x) {
                int t = pq.top();
                
                if (t == 0)
                    return ans;
                
                pq.pop();
                pq.push(--t);
                ans++;
            }
        }
        return ans;
    }
};
/*
Runtime: 60 ms, faster than 83.93% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
Memory Usage: 17.3 MB, less than 81.59% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
*/
