// [LeetCode] - Weekly Contest 265


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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int minD = 10000000, maxD = 0;
        
        ListNode *prev = head;
        ListNode *cont = head->next->next;
        head = head->next;
        int len = 0;
        bool firstCritical = true;
        
        while(cont) {
            
            len++;

            // if it is critical point
            if(head->val < prev->val && head->val < cont->val ||
                    head->val > prev->val && head->val > cont->val)
            {
                if(firstCritical) {
                    firstCritical = false;
                    len = 0;
                }
                else {
                    maxD += len;
                    minD = minD > len ? len : minD;
                    len = 0;
                }
            }            
            prev = head;
            head = cont;
            cont = cont->next;
        }
        
        minD = minD == 10000000 ? -1 : minD;
        maxD = maxD == 0 ? -1 : maxD;
        
        return(vector<int>({minD, maxD}));
    }
};