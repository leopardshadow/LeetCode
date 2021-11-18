/*
像這樣 deep copy 的題目，這題是 linked list，還有 graph 版本的
我是用 map 來存舊對應到新的地址，space complexity 是 O(n)，n 是 節點數量
但也有 O(1) 的做法，指來指去的，重複利用已經不用的 address
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* origHead) {
        map<Node*, Node*> m;
        m[NULL] = NULL;
        if(!origHead) return NULL;
        Node *origCur = origHead;
        Node *newHead = new Node(0), *newCur = newHead;
        while(origCur) {
            newCur->next = new Node(origCur->val);
            newCur = newCur->next;
            m[origCur] = newCur;
            origCur = origCur->next;
        }
        newHead = newHead->next;
        newCur = newHead;
        origCur = origHead;
        while(newCur) {
            newCur->random = m[origCur->random];
            newCur = newCur->next;
            origCur = origCur->next;
        }
        return newHead;
    }
};

/*
Runtime: 4 ms, faster than 97.86% of C++ online submissions for Copy List with Random Pointer.
Memory Usage: 11.5 MB, less than 8.26% of C++ online submissions for Copy List with Random Pointer.
*/
