/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// #include <stdlib.h>
// #include <stdbool.h>

// struct ListNode {
//     int val;
//     struct ListNode *next;
// };


// bool hasCycle(struct ListNode *head) {
    

//     // // memory-efficient but uses lots of time
//     // struct ListNode *curr = head;

//     // //               <= be careful about the edge cases !!
//     // for(int i = 0; i <= 10000; i++) {
//     //     if(curr == false) return false;
//     //     curr = curr->next;
//     // }
//     //          return true;
//     // /*
//     // Runtime: 8 ms, faster than 84.34% of C online submissions for Linked List Cycle.
//     // Memory Usage: 8.1 MB, less than 30.05% of C online submissions for Linked List Cycle.
//     // */

//     struct ListNode *slow = head,
//                     *fast = head;

//     while(fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//         if(fast == slow) return true;
//     }

//     return false;
//     /*
//     Runtime: 8 ms, faster than 84.34% of C online submissions for Linked List Cycle.
//     Memory Usage: 7.8 MB, less than 94.26% of C online submissions for Linked List Cycle.
//     */
// }



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode n;
        ListNode *addr = &n,
                 *temp;
        
        while(head) {
            if(head == addr) return true;
            temp = head;
            head = head->next;
            temp->next = addr;
        }
        
        return false;
    }
};

/*
Runtime: 4 ms, faster than 99.68% of C++ online submissions for Linked List Cycle.
Memory Usage: 8 MB, less than 58.64% of C++ online submissions for Linked List Cycle.
*/





//******************************************************************************//
// 2022.3.8

class Solution {
public:
    bool hasCycle(ListNode *head) {
        int len = 0;
        while(head) {
            if(++len > 10000)
                return true;
            head = head->next;
        }
        return false;
    }
};

/*
Runtime: 8 ms, faster than 95.50% of C++ online submissions for Linked List Cycle.
Memory Usage: 8.1 MB, less than 58.87% of C++ online submissions for Linked List Cycle.
*/
