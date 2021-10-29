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
          s   f
        s f
      *
even: a b x y c d -> y
odd:  a b x c d   -> x
      *
        s f
          s   f 
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
                
        ListNode *slow = head,
                 *fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;        
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
Memory Usage: 7 MB, less than 71.01% of C++ online submissions for Middle of the Linked List.
*/