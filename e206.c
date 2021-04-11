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

/*
    想法： 把原本指向後面的向前指
*/

struct ListNode* reverseList(struct ListNode* head){

    // 0 or only 1 elements
    if(!head || !head->next) return head;

    struct ListNode *prev = head,
                    *temp;

    head = head->next;
    prev->next = NULL;

    while(head) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;

    }

    return prev;
}

/*
Runtime: 4 ms, faster than 79.45% of C online submissions for Reverse Linked List.
Memory Usage: 6.2 MB, less than 88.88% of C online submissions for Reverse Linked List.
*/