
// 2022.1.7

/*
像這題不算有標準答案的 LeetCode 題感覺好少見 XD
---
這題給一個 linked list 的 head，要提供一個隨機回傳一個 node 值的 function
我的做法是先記錄長度，接著在每次 getRandom 時，決定要走多少長度到回傳的 node
---
TC: O(n): 每次都要走過很多 node
SC: O(1): 沒有耗費額外的空間來整條 kinked list
---
Follow-up 2: no extra space: 已經解了
---
Follow-up 1: 一個超長，不知道長度的 linked list
這個就比較有趣了
.
.
.
---
話說不知道他是怎麼測的，我一開始轉型沒處理好，只會回傳頭 node，結果有 WA
看起來他是跑超多資料去看統計數據正不正常
*/

class Solution {
    ListNode* head;
    int len;
public:
    
    Solution(ListNode* head) {
        this->head = head;
        len = 0;
        while(head) {
            head = head->next;
            len++;
        }
    }
    
    int getRandom() {
        ListNode *cur = head;
        int n = (int)( 1.0 * rand() / RAND_MAX * len );
        while(n) {
            cur = cur->next;
            n--;
        }
        return cur->val;
    }
};

/*
Runtime: 42 ms, faster than 6.90% of C++ online submissions for Linked List Random Node.
Memory Usage: 16.6 MB, less than 48.28% of C++ online submissions for Linked List Random Node.
*/
