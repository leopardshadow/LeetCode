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
    // if(l1 == NULL && l2 == NULL) {
    //     return NULL;
    // }
    if(l1 == NULL) {
        return l2;
    }
    else if (l2 == NULL){
        return l1;
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

    if(l1) {
        prev->next = l1;
    }
    if(l2) {
        prev->next = l2;
    }

    return head;
}


/*
Runtime: 4 ms, faster than 84.06% of C online submissions for Merge Two Sorted Lists.
Memory Usage: 6.1 MB, less than 55.13% of C online submissions for Merge Two Sorted Lists.
*/





// 2022.3.7

/*
上一次寫這題是四月面試前，距離現在已經快一年了 OAO
---
c -> cpp
---
之前寫得偏醜XD
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(), *curr = head;
        
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        
        while(list1) {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
        }
        while(list2) {
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        }
        
        return head->next;
    }
};
/*
Runtime: 3 ms, faster than 97.67% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 14.8 MB, less than 82.97% of C++ online submissions for Merge Two Sorted Lists.
*/
