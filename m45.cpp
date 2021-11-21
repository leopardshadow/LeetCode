// DP D4

/*
第一次寫自己的寫法
這題算是 55. Jump Game 的變形
只是 55. 算的是可不可以到最後一個，而這題則是問最小步數
我是用兩層迴圈去繞，更新從 i 往後 1~ nums[i] 的最小步數，但這樣比較慢
time complexity: O(n^2)
space complexity: O(n)
*/

/*
看到討論區有 time - O(n) / space - O(1) 的寫法 -- greedy BFS
這個想法一開始對我有一點點不直觀，不過還滿酷的，用 greedy 的寫法好漂亮

以 [2,3,1,1,4] 為例，從 index 0 開始，他最大可以走的步數是 2，可以到 index 1 或 2 的位置，從 0 走到 1 和 2 的最小步數都是 1
接著我們依序從 1 2 出發，看之後能走到哪，我們可以知道最小步數為 2 的是 3~ ??

說到 BFS 可能會想使用 queue 或標記走過誰，但在這題中不用，因為從 index 我們就可以知道走過誰，不用額外紀錄 (見下面說明)

在游泳池游泳時想了一下 XD
* 所需要的最小步數會是像 0 1 1 .. 1 2 2 .. 2 3 3 .. 3 ...，按照順序的，不會出現 0 1 2 3 1 這種亂跳的
* 如果到 index m 的最小步數是 n，則所有小於 m 的 index 的最小步數小於等於 n
*/

/*
i: 0 1 2 3 4
n: 2 3 1 1 4
*/

// 這是一開始自己的寫法
class Solution1 {
public:
    int jump(vector<int>& nums) {
        int maxIndex = 0;
        vector<int> minSteps(nums.size(), 100000);
        minSteps[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int step = 1; step <= nums[i] && i + step < nums.size(); step++) {
                minSteps[i + step] = min(minSteps[i] + 1, minSteps[i + step]);
            }
        }
        return minSteps.back();
    }
};

/*
Runtime: 404 ms, faster than 17.63% of C++ online submissions for Jump Game II.
Memory Usage: 17.1 MB, less than 14.21% of C++ online submissions for Jump Game II.
*/

/*
0 1 2 3 4
2 3 1 1 4
   (l, r)
0: (0, 0)  -1 -> 0
1: (1, 2)   0 -> 1
2: (3, 4)   1 -> 2
*/

// 後來看了別人解法寫的
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, steps = 0;
        int nextR = 0;
        // until r reaches the last element (r >= maxIndex, maxIndex = nums.size() - 1)
        while(r < nums.size() - 1) {  
            for(int i = l; i <= r; i++)
                nextR = max(nextR, i + nums[i]);
            l = r + 1;
            r = nextR;
            steps++;
        }
        return steps;
    }
};

/*
Runtime: 8 ms, faster than 98.40% of C++ online submissions for Jump Game II.
Memory Usage: 16.4 MB, less than 42.51% of C++ online submissions for Jump Game II.
*/
