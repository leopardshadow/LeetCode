// Hint. 2 heap
// https://blog.techbridge.cc/2020/03/15/leetcode-%E5%88%B7%E9%A1%8C-pattern-two-heaps/

class MedianFinder {
public:
    
    // size of minHeap is always equal or one bigger than maxHeap
    priority_queue <int, vector<int>, greater<int>> minHeap;
    priority_queue <int, vector<int>> maxHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(minHeap.size() == 0) {
            minHeap.push(num);
            return;
        }
        
        int tmp;
        // should add to maxHeap
        if(maxHeap.size() < minHeap.size()) {
            
            if(num > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else {
                maxHeap.push(num);
            }
        }
        // should add to minHeap
        else {
            if(num > maxHeap.top()) {
                minHeap.push(num);
            }
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


/*
Runtime: 280 ms, faster than 95.01% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 116.9 MB, less than 90.42% of C++ online submissions for Find Median from Data Stream.
*/