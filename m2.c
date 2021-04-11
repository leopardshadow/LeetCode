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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head, *temp;
    int carry = 0;

    head = malloc(sizeof(struct ListNode));
    temp = head;

    while(l1 && l2) {
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    // copy the rest
    while(l1) {
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = (l1->val + carry) % 10;
        carry = (l1->val +carry) / 10;
        l1 = l1->next;
    }
    while(l2) {
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = (l2->val + carry) % 10;
        carry = (l2->val +carry) / 10;
        l2 = l2->next;
    }
    if(carry) {
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = carry;
    }
    temp->next = NULL;
    return head->next;
}

int main(int argc, char const *argv[])
{


    return 0;
}
