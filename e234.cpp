
//******************************************************************************//
// 12.29 - Just Before A VO

/*
好偷懶的作法
---
O(1) space 可以先找到中間點，把後半 reverse 後，一個一個對，就不用額外存的空間
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        for(int i = 0; i < v.size(); i++) {
            if(v[i] != v[v.size() - i - 1])
                return false;
        }
        return true;
    }
};

/*
Runtime: 212 ms, faster than 54.44% of C++ online submissions for Palindrome Linked List.
Memory Usage: 128 MB, less than 19.10% of C++ online submissions for Palindrome Linked List.
*/
