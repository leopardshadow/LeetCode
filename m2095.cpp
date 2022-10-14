
// 2022.10.14

/*
1 2 3
  a
    b
----------
1 2 3 4
    a
         b
----------
2 1
  a
    b
----------
小心 edge cases
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // 1 node & 2 nodes
        if (!head->next)
            return nullptr;
        else if (!head->next->next) {
            head->next = nullptr;
            return head;
        }
        
        ListNode *a = head, *b = head;
        while (b && b->next) {
            a = a->next;
            b = b->next->next;
        }
        // "delete" node a (LC237)
        a->val = a->next->val;
        a->next = a->next->next;
        return head;
    }
};

