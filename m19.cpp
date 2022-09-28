/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len = 0, move;
    struct ListNode *cur = head;
    while(cur) {
        ++len;
        cur = cur->next;
    }
    cur = head;

    move = len - n - 1;
    if(move < 0) {  // i.e len == n => removee head
        return head->next;
    }
    for( ; move > 0; --move) {
        cur = cur->next;
    }
    // now cur points to the previous one of the target
    cur->next = cur->next->next;
    return head;
}

/*
Runtime: 4 ms, faster than 54.37% of C online submissions for Remove Nth Node From End of List.
Memory Usage: 6 MB, less than 8.63% of C online submissions for Remove Nth Node From End of List.
*/


//***************************************************************************//
// Review: 2021.11.28 before G VO

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node1 = head, *node2 = head;
        ListNode *prev;
        while(n) {
            node2 = node2->next;
            n--;
        }
        while(node2) {
            prev = node1;
            node1 = node1->next;
            node2 = node2->next;
        }
        // new we'd like to remove node1
        if(node1 == head)
            head = head->next;
        else
            prev->next = node1->next;
        delete node1;
        return head;
    }
};

/*
Runtime: 4 ms, faster than 79.05% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.8 MB, less than 31.77% of C++ online submissions for Remove Nth Node From End of List.
*/


// 2022.9.28
