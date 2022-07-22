
// 2022.7.22

/*
用 dummy node~
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lt_head = new ListNode(), *lt_tail = lt_head,
                 *ge_head = new ListNode(), *ge_tail = ge_head;
        
        ListNode *curr = head; 
        while (curr) {
            
            if (curr->val >= x) {
                ge_tail->next = curr;
                ge_tail = curr;
            }
            else {
                lt_tail->next = curr;
                lt_tail = curr;
            }
            curr = curr->next;
        }
        
        lt_tail->next = ge_head->next;
        ge_tail->next = nullptr;
        
        return lt_head->next;
    }
};
/*
Runtime: 8 ms, faster than 59.82% of C++ online submissions for Partition List.
Memory Usage: 10.3 MB, less than 73.43% of C++ online submissions for Partition List.
*/
