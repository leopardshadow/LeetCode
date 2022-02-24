
// 2022.2.24

/*
這題又是那種直接硬幹很簡單，但是有 complexity 整整好一個 order 的題目
---
題目的 follow-up 是 TC O(n log n) 及 SC O(1)
TC 的限制不是所有排序演算法都能用，像 bubble sort、selection sort 都不符合要求
可以用 merge sort，但我今天好懶w
*/

/*
偷懶作法
TC: O(n log n)
SC: O(n)
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;
        while(curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        sort(v.begin(), v.end());
        curr = head;
        for(int i = 0; i < v.size(); i++) {
            curr->val = v[i];
            curr = curr->next;
        }
        return head;
    }
};
/*
Runtime: 182 ms, faster than 27.62% of C++ online submissions for Sort List.
Memory Usage: 30.2 MB, less than 58.48% of C++ online submissions for Sort List.
*/
