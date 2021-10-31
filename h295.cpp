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
            // 這裡這樣寫比較精簡，之前一堆比較的...
            // 想法是現在要加到 maxHeap 去，但又要維持 minHeap 元素都比 maxHeap 大
            // 所以先丟到 minHeap 去，再把 minHeap 最小的 pop 出來丟到 maxHeap
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        // should add to minHeap
        else {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
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

///////////////////////////////////////


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
            // 這裡這樣寫比較精簡，之前一堆比較的...
            // 想法是現在要加到 maxHeap 去，但又要維持 minHeap 元素都比 maxHeap 大
            // 所以先丟到 minHeap 去，再把 minHeap 最小的 pop 出來丟到 maxHeap
            // 不過這樣時間比較久一點，畢竟是讓 heap 在那邊幫我們慢慢做事
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        // should add to minHeap
        else {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return minHeap.top();
    }
};

/*
Runtime: 304 ms, faster than 73.62% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 116.9 MB, less than 90.42% of C++ online submissions for Find Median from Data Stream.
*/