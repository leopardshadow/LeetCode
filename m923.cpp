
// 2022.4.6

/*
這題是 https://leetcode.com/problems/3sum/ 的變形
---
我把他分成 3 個 case 來處理，要注意這三個 case 有沒有重疊到，不然可能多算或少算
---
lee215 的作法也算是分成三個 case，但是用一組雙層迴圈來寫，解法好漂亮，不需要用到很多判斷條件，大致上是

把 i 跑一次：
    把 j 跑一次：
        依 target 計算出 k (k = target - i - j)：
            case aaa (i == j && j == k):
                ans 加上 C cnt(i) 取 3
            case aab (i == j && j != k):
                ans 加上 C cnt(i) 取 2 * cnt(k) 
            case abc (i < j  && j < k):
                ans 加上 cnt(i) * cnt(j) * cnt(k)
---
有兩個 0，在計算 C 時，n * (n - 1) * (n - 2) / 6 就會變成 0，不用特別處理
*/

#define MODU 1000000007

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> m;
        for (int n : arr)
            m[n]++;
        
        long ans = 0, temp, tmp2;

        // a a a
        if (target % 3 == 0 && m.count(target / 3) && m[target / 3] >= 3) {
            temp = m[target / 3];
            ans = (ans + temp * (temp - 1) / 2 * (temp - 2) / 3) % MODU;
        }

        // a a b
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second < 2 || 
                target - 2 * it->first == it->first || 
                m.count(target- 2 * it->first) <= 0)
                continue;
            temp = it->second;
            tmp2 = m[target- 2 * it->first];
            ans = (ans + temp * (temp - 1) / 2 * tmp2) % MODU;
        }
        
        // a b c
        for (auto it1 = m.begin(); it1 != m.end(); it1++) {
            for (auto it2 = m.begin() ; it2 != m.end(); it2++) {
                int k = target - it1->first - it2->first;
                if (k > it2->first && it2->first > it1->first && m.count(k))
                    ans = (ans + it1->second * it2->second * m[k]) % MODU;
            }
        }
        
        return ans;
    }
};
/*
Runtime: 25 ms, faster than 74.83% of C++ online submissions for 3Sum With Multiplicity.
Memory Usage: 10.5 MB, less than 62.58% of C++ online submissions for 3Sum With Multiplicity.
*/
