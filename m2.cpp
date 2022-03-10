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











//******************************************************************************//
// 2022.3.10

/*
這週好像是 linked list 週
---
注意 carry 要加到什麼時候
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy_head = new ListNode(), *curr = dummy_head;
        int carry = 0, sum;
        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            carry = sum >= 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *l = (l1 ? l1 : l2);
        while(l) {
            sum = l->val + carry;
            carry = sum >= 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l = l->next;
        }
        if(carry)
            curr->next = new ListNode(carry);
        return dummy_head->next;
    }
};

/*
Runtime: 78 ms, faster than 12.46% of C++ online submissions for Add Two Numbers.
Memory Usage: 71.5 MB, less than 50.05% of C++ online submissions for Add Two Numbers.
*/




/*
這題測資滿大的，所以不用 / 和 % 對執行時間上應該是有幫助
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy_head = new ListNode(), *curr = dummy_head;
        int carry = 0, sum;
        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            if(sum > 9) {
                sum -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            curr->next = new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *l = (l1 ? l1 : l2);
        while(l) {
            sum = l->val + carry;
            if(sum > 9) {
                sum -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            curr->next = new ListNode(sum);
            curr = curr->next;
            l = l->next;
        }
        if(carry)
            curr->next = new ListNode(carry);
        return dummy_head->next;
    }
};

/*
Runtime: 34 ms, faster than 79.33% of C++ online submissions for Add Two Numbers.
Memory Usage: 71.5 MB, less than 11.57% of C++ online submissions for Add Two Numbers.
*/
