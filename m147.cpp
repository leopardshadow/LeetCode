// 2021.12.15

/*
insertion sort Time Complexity:

Best: O(n) -- 當每次都只要插在頭時
Avg.: O(n^2)
Worst: O(n^2)
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode *sorted = new ListNode(INT_MIN);
        ListNode *cur = head, *insertPtr;
        
        while(cur) {
            
            insertPtr = sorted;
            
            // find the place to insert
            while(insertPtr->next && insertPtr->next->val < cur->val) {
                insertPtr = insertPtr->next;
            }
            
            // insert
            ListNode *temp = insertPtr->next;
            ListNode *nextCur = cur->next;  // 因為 cur->next 有被改掉，所以也要先存起來
            insertPtr->next = cur;
            cur->next = temp;

            //
            cur = nextCur;
        }
        return sorted->next;
    }
};

/*
Runtime: 68 ms, faster than 15.44% of C++ online submissions for Insertion Sort List.
Memory Usage: 9.6 MB, less than 71.76% of C++ online submissions for Insertion Sort List.
*/
