// Weekly Contest 286

/*
今天的 Contest 是三題保衛戰因為這題 ... 還好最後有成功，果然這次四題中通過率最低的是他
---
一次 WA 因為沒注意到 p10 的範圍，要寫 long long，int 不夠，不然其實可以一次 AC 的
---
length = 5 的 palindrome 有 3 個數字的自由度 ; 
length = 6 的 palindrome 也有 3 個數字的自由度。
這些自由的數字可以是 [0, 9]，除了 palindrome 第一位不能是 0，他只能是 [1, 9]。
---
第幾個 palindrome，他的那幾個自由數字應該是什麼，決定的方式跟數字的進位系統很像。
000 -> 001 -> 002 -> ...  最高位是九進位 (其實也用不到，只要記得 +1 就好)，其他都是正常的十進位。
xyz 在弄成迴文時，擺法是 (z+1) y x y (z+1)
000 10001
001 10101
...
(意思大概是這樣啦，可能和 code 有一點點一小不同 (?))
*/

typedef long long ll;

class Solution {
    vector<long long> p10;
    ll genPalin(vector<int> &nums, int len) {
        ll palin = 0;
        for(int i = 0; i < len; i++) {
            palin = palin + (i < nums.size() ? nums[i] : nums[len - 1 - i]) * p10[len - 1 - i];
        }
            
        return palin;
    }
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        
        ll p = 1;
        for(int i = 0; i <= 14; i++) {
            p10.push_back(p);
            p *= 10;
        }
        p10.push_back(p);
                
        vector<ll> ans;
        
        vector<int> ns(intLength / 2 + intLength % 2);
        
        for(int q : queries) {
            q--; // index from 1
            
            int t = intLength / 2 + intLength % 2;
            
            if(q >= (int)(9*pow(10, t - 1))) {
                ans.push_back(-1);
                continue;
            }
                        
            int i;
            for(i = t - 1; i >= 1; i--) {
                ns[i] = q % 10;
                q /= 10;
            }
            ns[0] = q % 9 + 1;
                        
            ans.push_back(genPalin(ns, intLength));
        }
        
        return ans;
    }
};
/*
Runtime: 198 ms, faster than 88.24% of C++ online submissions for Find Palindrome With Fixed Length.
Memory Usage: 54.1 MB, less than 100.00% of C++ online submissions for Find Palindrome With Fixed Length.
*/
