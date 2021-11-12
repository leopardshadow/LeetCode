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


///////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) {
            head = head->next;
        }
        if(!head) return head;

        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur) {
            if(cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            }
            else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return head;
    }
};

/*
Runtime: 12 ms, faster than 99.81% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 15.1 MB, less than 43.33% of C++ online submissions for Remove Linked List Elements.
*/
