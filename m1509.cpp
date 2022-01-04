// Google 

/*
Hint.
他的提示說的差不多了 XD
The minimum difference possible is is obtained by removing 3 elements between the 3 smallest and 3 largest values in the array.
但我是看了提示才會的 QQ
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int n = nums.size();
        ans = min(ans, nums[n-4] - nums[0]);
        ans = min(ans, nums[n-3] - nums[1]);
        ans = min(ans, nums[n-2] - nums[2]);
        ans = min(ans, nums[n-1] - nums[3]);
        return ans;
    }
};

/*
Runtime: 80 ms, faster than 92.08% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
Memory Usage: 35.3 MB, less than 51.17% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
*/


//******************************************************************************//

/*
看到這題回來翻了一下，覺得之前的寫法有點花時間，我只需要存最大和最小的 3 個，應該可以不要對整個陣列排序
所以我分別用兩個大小為 4 的 heap 存，這樣複雜度從 n log n 降成 n log 4
但實際執行起來跑的時間卻變久 ... 好怪
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        if(nums.size() <= 4)
            return 0;
        
        priority_queue<int> minHeap;
        priority_queue<int, vector<int>, greater<int>> maxHeap;
        
        for(int i = 0; i < 4; i++) {
            minHeap.push(nums[i]);
            maxHeap.push(nums[i]);
        }
        // keeps the size of heap 4
        for(int i = 4; i < nums.size(); i++) {
            minHeap.push(nums[i]);
            minHeap.pop();
            maxHeap.push(nums[i]);
            maxHeap.pop();
        }
        int big[4], small[4];
        for(int i = 0; i < 4; i++) {
            big[i] = maxHeap.top();
            maxHeap.pop();
            small[3 - i] = minHeap.top();
            minHeap.pop();
        }
        int ans = INT_MAX;
        for(int i = 0; i < 4; i++) {
            ans = min(ans, big[i] - small[i]);
        }
        return ans;
    }
};

/*
Runtime: 239 ms, faster than 5.24% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
Memory Usage: 35.3 MB, less than 10.41% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
*/
