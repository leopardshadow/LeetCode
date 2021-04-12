
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    struct ListNode *tmp, *ret = NULL;
    tmp = headA;
    while(tmp) {
        tmp->val += 1000000;
        tmp = tmp->next;
    }
    tmp = headB;
    while ((tmp))
    {
        if(tmp->val > 1000000) {
            ret = tmp;
            break;
        }
        tmp = tmp->next;
    }
    tmp = headA;
    while(tmp) {
        tmp->val -= 1000000;
        tmp = tmp->next;
    }
    return ret;
}

/*
Runtime: 36 ms, faster than 55.44% of C online submissions for Intersection of Two Linked Lists.
Memory Usage: 13.8 MB, less than 78.34% of C online submissions for Intersection of Two Linked Lists.
*/