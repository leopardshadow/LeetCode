// 2021.12.7

/*
因為他的順序是 linked list 往下的順序，所以一定要走兩次，或是 stack 先存著，再一層一層返回 (recursively)
如果是倒序的存就比較簡單
*/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            len++;
            cur = cur->next;
        }
        int ans = 0;
        cur = head;
        len--;
        while(cur) {
            if(cur->val == 1)
                ans = ans | (1 << len);
            len--;
            cur = cur->next;
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 46.25% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
Memory Usage: 8.2 MB, less than 59.92% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
*/
