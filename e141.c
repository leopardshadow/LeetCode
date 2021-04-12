/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


bool hasCycle(struct ListNode *head) {
    

    // // memory-efficient but uses lots of time
    // struct ListNode *curr = head;

    // //               <= be careful about the edge cases !!
    // for(int i = 0; i <= 10000; i++) {
    //     if(curr == false) return false;
    //     curr = curr->next;
    // }
    //          return true;
    // /*
    // Runtime: 8 ms, faster than 84.34% of C online submissions for Linked List Cycle.
    // Memory Usage: 8.1 MB, less than 30.05% of C online submissions for Linked List Cycle.
    // */

    struct ListNode *slow = head,
                    *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return true;
    }

    return false;
    /*
    Runtime: 8 ms, faster than 84.34% of C online submissions for Linked List Cycle.
    Memory Usage: 7.8 MB, less than 94.26% of C online submissions for Linked List Cycle.
    */
}