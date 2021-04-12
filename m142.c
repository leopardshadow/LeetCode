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


struct ListNode *detectCycle(struct ListNode *head) {

    struct ListNode *kthp = head;

    // pos ?????
    while(pos) {
        pos--;
        kthp = kthp->next;
    }
    return kthp;
}