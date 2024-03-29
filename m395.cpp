/*
第一眼看起來是 sliding window 的題目
感覺可以用 divide & conquer 解
---
不看解答寫的，看一下討論區的 tag，果然主要是這兩種
(寫的時候一樓有人一直大聲講電話，估計整棟都聽得到，煩死，怎麼可以這麼吵)
---
我的想法是這樣的..
當我把整串字串跑過一遍後，我會知道各個字元出現的的頻率。
如果該字元有出現過但次數不滿 k，那些字元就形成了界線，我在取 substring 時一定不能包含他們。
原本的字元被那些出現不滿 k 次的切開成很多 substring，這些 substring 再往下 recursivly 得做，
直到那個字串從頭到尾出現字元的次數都 >= k
---
看到討論區類似的寫法不是像我一樣用 l, r 表示頭尾，而是用 substr，看起來比較簡潔
*/

class Solution {
    int ans;
public:
    int longestSubstring(string s, int k) {
        ans = 0;
        solve(s, k, 0, s.length() - 1);
        return ans;
    }
    
    void solve(string &s, int &k, int l, int r) {
        if(l > r) return;
        if(r - l + 1 <= ans) return;
        
        int cnt[26] = {0};
        for(int i = l; i <= r; i++)
            cnt[s[i] - 'a']++;
        
        bool allK = true;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] > 0 && cnt[i] < k) {
                allK = false;
                break;
            }
        }
        if(allK) {
            ans = max(ans, r - l + 1);
            return;
        }
        int j = l;
        int prevJ = l;
        while(j <= r) {
            if(cnt[s[j] - 'a'] > 0 && cnt[s[j] - 'a'] < k) {
                solve(s, k, prevJ, j-1);
                prevJ = j + 1;
            }
            j++;
        }
        solve(s, k, prevJ, j-1);
    }
};


// 把 void solve(string &s, int &k, int l, int r) 的 s 和 k 改成 call by reference，performance 瞬間飆上去，酷ㄟ
// 話說為了確認他沒有騙我，我再點一次 submit，使用記憶體仍然是 6.3 MB 但變成 94.81% ????? 
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
Memory Usage: 6.3 MB, less than 82.09% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
*/

/*
Runtime: 8 ms, faster than 49.18% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
Memory Usage: 75.7 MB, less than 5.26% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
*/
