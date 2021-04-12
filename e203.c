/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* removeElements(struct ListNode* head, int val){

    struct ListNode leading_node;
    leading_node.next = head;

    struct ListNode *prev = &leading_node,
                    *curr = head;

    while(curr) {
        // process
        if(curr->val == val) {
            prev->next = curr->next;
            curr = curr->next;
        }
        else {
            // iter
            prev = curr;
            curr = curr->next;
        }
        
    }

    return leading_node.next;
}