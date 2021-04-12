/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// #include <stdio.h>

// struct ListNode {
//     int val;
//     struct ListNode *next;
// };


/*
    Hint.
    slow-fast pointer
*/

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNodes(struct ListNode* head, int k){
    
    struct ListNode *slow,
                    *fast,
                    *kthp = head;
    int i;
    for(i = 0; i < k - 1; i++) {
        kthp = kthp->next;
    }

    slow = head;
    fast = kthp->next;

    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // swap kthp's value and slow's value
    int tmp = kthp->val;
    kthp->val = slow->val;
    slow->val = tmp;

    return head;
}

/*
Runtime: 244 ms, faster than 18.22% of C online submissions for Swapping Nodes in a Linked List.
Memory Usage: 48.5 MB, less than 19.92% of C online submissions for Swapping Nodes in a Linked List.
*/