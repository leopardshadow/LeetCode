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