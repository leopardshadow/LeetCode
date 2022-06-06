
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


// COOL solution from https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/1092898/JS-Python-Java-C%2B%2B-or-Easy-O(1)-Extra-Space-Solution-w-Visual-Explanation
/*
A: (1 2) 8 9
B: (4 5 6) 8 9

        /  a  \ /    b    \
A + B = 1 2 8 9 4 5 6 (8 9)
B + A = 4 5 6 8 9 1 2 (8 9)
        \   b   / \   a   /
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

        struct ListNode *a = headA, *b = headB;
        while (a != b) {
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }
        return a;
}
/*
Runtime: 36 ms, faster than 55.44% of C online submissions for Intersection of Two Linked Lists.
Memory Usage: 14.1 MB, less than 11.68% of C online submissions for Intersection of Two Linked Lists.
*/



//******************************************************************************//


// 2022.6.6

/*
共同的部分改了 A，B 也會看到
偷偷改了他的結構再改回來
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        while(a) {
            a->val = -a->val;
            a = a->next;
        }
        
        ListNode *b = headB, *ret = NULL;
        while(b) {
            if (b->val < 0) {
                ret = b;
                break;
            }
            b = b->next;
        }
        
        // restore to original
        a = headA;
        while(a) {
            a->val = -a->val;
            a = a->next;
        }
        
        return ret;  // no intersection
    }
};
/*
Runtime: 64 ms, faster than 48.52% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 14.6 MB, less than 72.44% of C++ online submissions for Intersection of Two Linked Lists.
*/
