// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */

// #include <stdio.h>

// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

/*
    Note.
    除了換值，也可以改變指向!! 不要被 "示意圖" 限制住
    先從奇數和偶數第一個開始，各別隔著指，最後再接在一起
    注意每一題不同的範圍和條件，像這題就有 [] 的邊緣測資要考慮
    花了一些時間在找錯
*/

struct ListNode* oddEvenList(struct ListNode* head) {

    struct ListNode *odd = head,
                    *even = odd ? head->next : NULL,
                    *the_second = even;
    
    //    vvv ---> for input [] ...
    while(odd && odd->next && even->next) {

        // process
        odd->next = odd->next->next;
        even->next = even->next->next;

        // update
        odd = odd->next;
        even = even->next;
    }

    if(odd)
        odd->next = the_second; // get stuck here, because direction has been changed

    return head;
}

/*
Runtime: 4 ms, faster than 94.05% of C online submissions for Odd Even Linked List.
Memory Usage: 6.8 MB, less than 100.00% of C online submissions for Odd Even Linked List.
*/

/*
Runtime: 4 ms, faster than 91.43% of C online submissions for Odd Even Linked List.
Memory Usage: 6.8 MB, less than 72.50% of C online submissions for Odd Even Linked List.
*/
