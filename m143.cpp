/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
1 2 3 4
---------
1 2
3 4
----------
1 2
4 3
-----------
1 4 2 3
*/


/*
Solution 1: brute-force
Solution 2: use fast-slow pointer to find the mid-point
            reverse the second half part
            then interleave the two lists
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // use slow-fast pointer to get mid-point
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the list starting from slow
        ListNode *prev = NULL, *temp;
        while(slow) {
            temp = slow;
            slow = slow->next;
            temp->next = prev;
            prev = temp;
        }
        
        ListNode *a = head;
        ListNode *b = temp; // len of b is equal or one bigger than a
        ListNode *tmpA, *tmpB;
        
        while(a && b) {
            tmpA = a;
            tmpB = b;
            a = a->next;
            b = b->next;
            tmpA->next = tmpB;
            tmpB->next = a;
        }
        tmpB->next = NULL;  // needs this for even-length case!
    }
};

/*
Runtime: 36 ms, faster than 88.05% of C++ online submissions for Reorder List.
Memory Usage: 17.7 MB, less than 76.61% of C++ online submissions for Reorder List.
*/