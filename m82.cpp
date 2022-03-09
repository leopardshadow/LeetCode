
//******************************************************************************//
// 2022.3.9

/*
12.28 - 1 Day Before A VO
那時候想寫，但沒寫完，今天想偷懶直接交吃了一個 WA...
*/

/*
這題麻煩的是只能留 distinct 的 nodes
應該是有更好的作法辣
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> rms;
        ListNode *curr = head, *prev;
        while(curr && curr->next) {
            if(curr->val == curr->next->val)
                rms.insert(curr->val);
            curr = curr->next;
        }
        
        ListNode *dummy_head = new ListNode(-1, head);
        curr = head;
        prev = dummy_head;
        while(curr) {
            if(rms.count(curr->val)) {
                prev->next = curr->next;
                curr = curr->next;
            }
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return dummy_head->next;
    }
};

/*
Runtime: 12 ms, faster than 47.39% of C++ online submissions for Remove Duplicates from Sorted List II.
Memory Usage: 11.5 MB, less than 10.61% of C++ online submissions for Remove Duplicates from Sorted List II.
*/
