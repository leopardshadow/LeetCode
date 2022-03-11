
// 2022.3.11

/*
注意一些 edge cases，像是空的 list 和只有一個 node 的 list
---
我的解法是：
1. 先找到整條 list 的長度
2. 把 k mod len，確保不會繞出去
3. 用 fast/slow pointer (fast 領先 slow k 個) 找到要斷開的點
4. 把尾接回頭，斷開的點前面要改成 nullptr，後面是回傳值
---
這裡要特別注意一定要加上 nullptr
我一開始這裡沒有處理好，一直出現錯誤，後來才發現我寫的 function 跑的過程中沒有出錯，是他在執行時判斷對錯時報錯 
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return nullptr;
        
        int len = 0;
        ListNode *curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        if(len != 0)  // avoid division by zero
            k = k % len;
                
        ListNode *fast = head, *slow = head;
        for(int i = 0; i < k; i++)
            fast = fast->next;
            
        while(fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *ans = slow->next ? slow->next : head;  // QQ
        fast->next = head;
        slow->next = nullptr;
        
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 94.34% of C++ online submissions for Rotate List.
Memory Usage: 11.8 MB, less than 55.87% of C++ online submissions for Rotate List.
*/
