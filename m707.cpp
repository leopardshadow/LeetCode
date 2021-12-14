class Node {
public:
    int val;
    Node *prev, *next;
    Node(int val) {
        this->val = val;
    }
};

class MyLinkedList {
    Node *head, *tail;
public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        Node *cur = head;
        while(index && cur) {
            cur = cur->next;
            index--;
        }
        if(!cur)
            return -1;
        return cur->val;
    }
    
    void addAtHead(int val) {
        if(!head) {
            head = new Node(val);
            tail = head;
        }
        else {
            Node *cur = new Node(val);
            cur->next = head;
            head->prev = cur;
            head = cur;
        }
    }
    
    void addAtTail(int val) {
        if(!head) {
            head = new Node(val);
            tail = head;
        }
        else {
            Node *cur = new Node(val);
            cur->prev = tail;
            tail->next = cur;
            tail = cur;
        }
    }
    
    void addAtIndex(int index, int val) {
        
    }
    
    void deleteAtIndex(int index) {
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
