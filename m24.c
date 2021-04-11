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
    想法：
    兩兩一組，互換數字
    這一組有一個沒東西就離開
*/

struct ListNode* swapPairs(struct ListNode* head){

    if(!head) return NULL;
    struct ListNode *first  = head,
                    *second = head->next;
    int tmp;
    while(first && second) {
        // swap value of first and second
        tmp = first->val;
        first->val = second->val;
        second->val = tmp;

        // update value
        if((first = second->next) == NULL || (second = first->next) == NULL)
            break;
    }
    return head;
}

/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Swap Nodes in Pairs.
Memory Usage: 6 MB, less than 23.22% of C online submissions for Swap Nodes in Pairs.
*/