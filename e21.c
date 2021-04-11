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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *prev, *head;

    // be careful with the edge case ...
    if(l1 == NULL && l2 == NULL) {
        return NULL;
    }
    if(l1 == NULL) {
        head = l2;
        l2 = l2->next;
    }
    else if (l2 == NULL){
        head = l1;
        l1 = l1->next;
    }
    else if (l1->val > l2->val) {
        head = l2;
        l2 = l2->next;
    }
    else {
        head = l1;
        l1 = l1->next;
    }

    prev = head;

    while(l1 && l2) {
        // append the smaller one
        if(l1->val < l2->val) {
            prev->next = l1;
            prev = l1;
            l1 = l1->next;
        }
        else {
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
        }
    }

    while(l1) {
        // append l1->val
        prev->next = l1;
        prev = l1;
        l1 = l1->next;
    }

    while(l2) {
        // append l2->val
        prev->next = l2;
        prev = l2;
        l2 = l2->next;
    }

    return head;
}


/*
Runtime: 4 ms, faster than 84.06% of C online submissions for Merge Two Sorted Lists.
Memory Usage: 6.3 MB, less than 40.13% of C online submissions for Merge Two Sorted Lists.
*/