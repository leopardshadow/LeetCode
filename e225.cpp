
// 2022.5.4

/*
這題的 follow-up 是只用一個 queue，看了討論區
一開始直接想 size = 3，但是 3 是從 2 來的，他在 queue 不會一樣..
*/

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return !q.size();
    }
};
/*
Runtime: 2 ms, faster than 40.64% of C++ online submissions for Implement Stack using Queues.
Memory Usage: 6.9 MB, less than 58.19% of C++ online submissions for Implement Stack using Queues.
*/
