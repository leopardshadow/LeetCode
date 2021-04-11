/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
    Note.
    除了換值，也可以改變指向!! 不要被 "示意圖" 限制住
    先從奇數和偶數第一個開始，各別隔著指，最後再接在一起
*/

struct ListNode* oddEvenList(struct ListNode* head) {

    struct ListNode *odd = head,
                    *even = head->next;
    
    while(!odd->next || !even->next) {

        // process
        odd->next = odd->next->next;
        if(!even->next) break;
        even->next = even->next->next;

        // if(!odd->next || !even->next)
        //     break;

        // update
        odd = odd->next;
        even = even->next;
    }

    odd->next = head->next;
    even->next = NULL;

    return head;
}

