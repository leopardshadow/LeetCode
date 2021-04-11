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

/*
    這題還滿有趣的，有點腦筋急轉彎的感覺，
    要刪一個 node，但不是給頭，而是給要被刪的那位的指標
    因為是單向的 linked list，所以我們無法知道前面是誰，當然也無法改變他的指向
    但是我們可以改變後面的! 逝者已矣，來者猶可追 XD
    題目的圖其實有一點誤導，
    想法是，前面一個指向我就算了，我無法更改，但是我可以改變自己的值和指向!!

    難怪題目要特別強調 > The node to be deleted is in the list and is not a tail node
*/

void deleteNode(struct ListNode* node) {
    node->val = (node->next)->val;
    node->next = (node->next)->next;
    // free the memory ??
}

/*
Runtime: 4 ms, faster than 92.85% of C online submissions for Delete Node in a Linked List.
Memory Usage: 6.5 MB, less than 31.68% of C online submissions for Delete Node in a Linked List.
*/