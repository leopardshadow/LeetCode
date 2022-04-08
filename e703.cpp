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
/*
Runtime: 32 ms, faster than 84.76% of C++ online submissions for Kth Largest Element in a Stream.
Memory Usage: 19.7 MB, less than 92.23% of C++ online submissions for Kth Largest Element in a Stream.
*/




// 2022.4.8

/*
K th largest 維護一個 size 為 k 的 min heap，這個 min heap 會儲存前 k 大的數，每次加入新的都會把最小的幾個踢掉，讓它維持 size = k 後回傳 min heap 頂端的值
*/

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : pq(nums.begin(), nums.end()) {
        this->k = k;
        while (pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};
/*
Runtime: 35 ms, faster than 82.41% of C++ online submissions for Kth Largest Element in a Stream.
Memory Usage: 19.9 MB, less than 63.09% of C++ online submissions for Kth Largest Element in a Stream.
*/
