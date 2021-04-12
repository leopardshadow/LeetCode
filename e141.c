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
    

    // memory-efficient but uses lots of time
    struct ListNode *curr = head;

    //               <= be careful about the edge cases !!
    for(int i = 0; i <= 10000; i++) {
        if(curr == false) return false;
        curr = curr->next;
    }

    return true;
}