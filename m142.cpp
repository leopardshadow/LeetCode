
// 2022.1.19

/*
題目要求不能修改 list 又希望只用 constant memory，可以用快慢指針
但我今天好懶w
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> m;
        while(head) {
            if(m.count(head))
                return head;
            m.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

/*
Runtime: 16 ms, faster than 24.22% of C++ online submissions for Linked List Cycle II.
Memory Usage: 9.6 MB, less than 10.02% of C++ online submissions for Linked List Cycle II.
*/
