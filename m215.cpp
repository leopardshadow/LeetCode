/*
Hint. keep an min-heap of size k
      discard redundant elements
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(const auto n : nums) {
            minHeap.push(n);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};

/*
Runtime: 8 ms, faster than 79.88% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.2 MB, less than 34.13% of C++ online submissions for Kth Largest Element in an Array.
*/