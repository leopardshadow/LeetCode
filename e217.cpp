// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         map <int, bool> m;
//         for(const auto n : nums) {
//             // there is duplicate
//             if(m.find(n) != m.end())
//                 return true;
//             // no duplicate number
//             else
//                 m[n] = true;
//         }
//         return false;
//     }
// };

/*
Runtime: 48 ms, faster than 33.31% of C++ online submissions for Contains Duplicate.
Memory Usage: 21 MB, less than 30.71% of C++ online submissions for Contains Duplicate.
*/

// another approach: sort!

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};

/*
Runtime: 26 ms, faster than 79.12% of C++ online submissions for Contains Duplicate.
Memory Usage: 15.3 MB, less than 99.99% of C++ online submissions for Contains Duplicate.
*/



//***************************************************************************//
// 2021.12.1 before G VO (今天的感覺炸了 QQ)

/*
之前是用 unordered_map，但其實用 unordered_set 比較好，畢竟我們只要知道有沒有出現過，
他出現幾次、出現在哪裡之類的資訊根本不重要
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> um;
        for(int n : nums) {
            if(um.count(n))
                return true;
            else
                um.insert(n);
        }
        return false;
    }
};
