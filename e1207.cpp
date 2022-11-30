
// 2022.11.30

/*
Easy
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        for (const int &n : arr)
            occur[n]++;
        unordered_set<int> uniq;
        for (auto x : occur) {
            if (uniq.count(x.second))
                return false;
            else
                uniq.insert(x.second);
        }
        return true;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Number of Occurrences.
Memory Usage: 8.3 MB, less than 20.75% of C++ online submissions for Unique Number of Occurrences.
*/
