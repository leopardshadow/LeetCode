
// 2022.7.21

/*
偷懶
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> xs;
        ListNode *curr = head;
        int i;
        for (i = 1; i < left; i++)
            curr = curr->next;
        for (; i <= right; i++) {
            xs.push_back(curr);
            curr = curr->next;
        }
        for (int i = 0; i < xs.size() / 2; i++) {
            swap(xs[i]->val, xs[xs.size() - 1 - i]->val);
        }
        
        return head;
    }
};
