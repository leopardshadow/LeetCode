
// 2022.7.4

/*
有兩邊要處理不一定要一起處理 (雖然有辦法可以處理，但寫的出來比較重要)
兩邊分開處理，用空間、時間換簡單的邏輯
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int>l(n, 1), r(n, 1);
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i-1])
                l[i] = l[i-1] + 1;
        
        for (int i = n - 2; i >= 0; i--)
            if (ratings[i] > ratings[i+1])
                r[i] = r[i+1] + 1;
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += max(l[i], r[i]);
        return ans;
    }
};
/*
Runtime: 62 ms, faster than 11.30% of C++ online submissions for Candy.
Memory Usage: 18.3 MB, less than 13.38% of C++ online submissions for Candy.
*/
