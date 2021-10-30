/*
Top K ... use heap!!
*/
class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n : nums) {
            minHeap.push(n);
            if(minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


/*
Runtime: 32 ms, faster than 84.76% of C++ online submissions for Kth Largest Element in a Stream.
Memory Usage: 19.7 MB, less than 92.23% of C++ online submissions for Kth Largest Element in a Stream.
*/