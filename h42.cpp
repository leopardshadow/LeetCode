// DP D9

/*
偷看了這題的 tag (monotonic stack) 之後有點想法
這是目前我的作法 (還沒看討論區 XD)
是有 AC 沒有 TLE 但好慢ㄛ 
---
用一個 stack 來紀錄，只有當這個數字大於 stack 頂端時才 push
以 example 1 為例子
        [0,1,0,2,1,0,1,3,2,1,2,1]
left  -    1   2       3          (從左邊開始)
right -                3     2 1  (從右邊開始)
建立這兩個 stack 後就可以算出水面高度，最後再減掉中間佔位的
---
幾點小細節要注意
1. 因為是預設沒有邊界的，所以一開始要排除兩端高度是 0 的傢伙，他們對總水量沒有任何貢獻
2. 一開始我判斷要不要 push 進 stack 用的是 >，應該要是 >=
   這樣有同樣高度的，例如 [2, 0, 2] 才不會出錯
3. 直接改成 >= 之後，同樣的 case [2, 0, 2] 會出錯，因為左邊右邊都會算一次
   所以在左邊算完後，右邊的 index 只要算到左邊那邊路最大的 index 就好
*/

class Solution {
public:
    int trap(vector<int>& height) {
        // pair: height, index
        deque<int> leftStack;
        deque<int> rightStack;
        
        int firstNonZero = 0;
        while(firstNonZero < height.size() && height[firstNonZero] == 0)
            firstNonZero++;
        leftStack.push_back(firstNonZero);
        for (int i = firstNonZero + 1; i < height.size(); i++) {
            if (height[i] >= height[leftStack.back()])
                leftStack.push_back(i);
        }
        
        int heighestIdx = leftStack.back();
        
        int lastNonZero = height.size() - 1;
        while(lastNonZero < height.size() && height[lastNonZero] == 0)
            lastNonZero--;
        rightStack.push_back(lastNonZero);
        for (int i = lastNonZero - 1; i >= heighestIdx; i--) {
            if (height[i] >= height[rightStack.back()])
                rightStack.push_back(i);
        }
        int ans = 0;
        for(int i = 0; i < leftStack.size() - 1; i++) {
            ans = ans + height[leftStack[i]] * (leftStack[i+1] - leftStack[i] - 1);
            for(int j = leftStack[i] + 1; j < leftStack[i+1]; j++)
                ans -= height[j];
        }
        for(int i = 0; i < rightStack.size() - 1; i++) {
            ans = ans + height[rightStack[i]] * (rightStack[i] - rightStack[i+1] - 1);
            for(int j = rightStack[i+1] + 1; j < rightStack[i]; j++)
                ans -= height[j];
        }
        return ans;
    }
};

/*
Runtime: 20 ms, faster than 11.10% of C++ online submissions for Trapping Rain Water.
Memory Usage: 16.6 MB, less than 5.90% of C++ online submissions for Trapping Rain Water.
*/

// 2022.9.18
