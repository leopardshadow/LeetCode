
// 2022.9.25

/*
標準的 circular queue~
*/

class MyCircularQueue {
    int k, front, size;
    vector<int> q;
public:
    MyCircularQueue(int k) {
        this->k = k;
        front = 0;
        size = 0;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        else {
            q[(front + size) % k] = value;
            size++;
            return true;
        }
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        else {
            front = (front + 1) % k;
            size--;
            return true;
        }
    }
    
    int Front() {
        if (size == 0)
            return -1;
        else
            return q[front];
    }
    
    int Rear() {
        if (size == 0)
            return -1;
        else
            return q[(front + size - 1) % k];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};
/*
Runtime: 59 ms, faster than 16.62% of C++ online submissions for Design Circular Queue.
Memory Usage: 16.9 MB, less than 48.83% of C++ online submissions for Design Circular Queue.
*/
