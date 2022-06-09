

// 2022.6.9

/*
剛好昨天複習了 binary search，今天剛好練一下這個能用二分搜做的
一看到 sorted，直覺就是 binary search
---
用 binary search 的 TC 是 O(n log n)
看了一下討論區，用 2-pointer 做的話可以到 TC O(n)，SC 仍是 O(1)
而且比較簡單
---
2-pointer
因為 l = 0, r = size() - 1 開始，l 只會變大，r 只會變小
如果 ns[l] + ns[r] 比 targ 大，代表整體要變小，r 只能 -1
*/

// 用 cplusplus 的 lower_bound
// 好慢。。。。

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        vector<int>::iterator pos;
        for (int i = 0; i < numbers.size(); i++) {
            pos = lower_bound(numbers.begin()+i+1, numbers.end(), target-numbers[i]);
            if (pos != numbers.end() && *pos == target-numbers[i]) {
                ans[0] = i + 1;
                ans[1] = (pos - numbers.begin()) + 1;
                break;
            }
        }
        
        return ans;
    }
};
/*
Runtime: 45 ms, faster than 5.14% of C++ online submissions for Two Sum II - Input Array Is Sorted.
Memory Usage: 15.6 MB, less than 75.27% of C++ online submissions for Two Sum II - Input Array Is Sorted.
*/


// 自己寫 binary search 

class Solution {
    int found(vector<int>& numbers, int start, int targ) {
        int left = start + 1, right = numbers.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] == targ)
                return mid;
            else if (numbers[mid] > targ)
                right = mid;
            else
                left = mid + 1;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int idx;
        for (int i = 0; i < numbers.size(); i++) {            
            if ((idx = found(numbers, i, target - numbers[i])) != -1) {
                ans[0] = i + 1;
                ans[1] = idx + 1;
                break;
            }
        }
        
        return ans;
    }
};
/*
Runtime: 25 ms, faster than 22.68% of C++ online submissions for Two Sum II - Input Array Is Sorted.
Memory Usage: 15.7 MB, less than 44.00% of C++ online submissions for Two Sum II - Input Array Is Sorted.
*/

// 2-pointer 的寫法
// 看了討論區的標題自己寫的 XD

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                ans[0] = l + 1;
                ans[1] = r + 1;
                break;
            }
            else if (numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }
        return ans;
    }
};
/*
Runtime: 28 ms, faster than 14.96% of C++ online submissions for Two Sum II - Input Array Is Sorted.
Memory Usage: 15.7 MB, less than 44.00% of C++ online submissions for Two Sum II - Input Array Is Sorted.
*/
