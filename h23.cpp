//***************************************************************************//
// 2021.12.2 before G VO (聽說一關炸掉，但其他關好還是可能過~)

class Solution {
    
    struct comp {
        bool operator() (const ListNode *p1, const ListNode *p2) {
            return p1->val > p2->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i])
                pq.push(lists[i]);
        }
        
        ListNode *root, *prev = NULL;
        if(pq.empty())
            root = NULL;
        else {
            root = pq.top();
            pq.pop();
            if(root->next)
                pq.push(root->next);
            prev = root;
        }
             
        while(!pq.empty()) {
            
            ListNode *cur = pq.top();
            pq.pop();
            if(cur->next)
                pq.push(cur->next);
            
            prev->next = cur;
            
            prev = cur;
        }
        
        return root;
    }
};

// 用 pair
/*
Runtime: 16 ms, faster than 97.61% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13.6 MB, less than 39.66% of C++ online submissions for Merge k Sorted Lists.
*/

// 只用 ListNode *
/*
Runtime: 20 ms, faster than 88.09% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13.4 MB, less than 59.20% of C++ online submissions for Merge k Sorted Lists.
*/
