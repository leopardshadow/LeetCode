
// 2022.9.15

/*
最小的值一定屬於原陣列，他的兩倍是屬於兩倍陣列，這兩個都確定屬於誰，可以從題目的陣列拔掉
接著就重複做，值到陣列變空或出現錯誤

要特別注意 0，0 * 2 = 0，如果 0 是偶數，就拆一半一半，如果是奇數則拆不了

這題沒有出現負數，如果有的話也可以做，只是正、負要分開處理，都是從 0 往左右走
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> xs;
        for (const int &n : changed)
            xs[n]++;
        
        vector<int> ans;
        
        if (xs.find(0) != xs.end()) {
            if (xs[0] % 2 == 0)
                for (int i = 0; i < xs[0] / 2; i++)
                    ans.push_back(0);
            else
                return {};
            xs.erase(0);
        }
        
        
        for (auto &x : xs) {
            int xx = 2 * x.first;
            if (xs.find(xx) != xs.end() && xs[xx] >= x.second) {
                xs[xx] -= x.second;
                for (int i = 0; i < x.second; i++)
                    ans.push_back(x.first);
                if (xs[xx] == 0)
                    xs.erase(xx);
            }
            else
                return {};
        }
        return ans;
    }
};
/*
Runtime: 499 ms, faster than 82.29% of C++ online submissions for Find Original Array From Doubled Array.
Memory Usage: 143.9 MB, less than 58.97% of C++ online submissions for Find Original Array From Doubled Array.
*/
