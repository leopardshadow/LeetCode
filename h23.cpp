//***************************************************************************//
// 2021.12.2 before G VO (聽說一關炸彈其他關好還是可能過~)

class Solution {
    
    struct comp {
        bool operator() (const pair<int, ListNode*> &p1, const pair<int, ListNode*> &p2) {
            return p1.first > p2.first;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, comp> pq;
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        
        ListNode *root, *prev = NULL;
        if(pq.empty())
            root = NULL;
        else {
            root = pq.top().second;
            pq.pop();
            if(root->next)
                pq.push({root->next->val, root->next});
            prev = root;
        }
             
        while(!pq.empty()) {
            
            ListNode *cur = pq.top().second;
            pq.pop();
            if(cur->next)
                pq.push({cur->next->val, cur->next});
            
            prev->next = cur;
            
            prev = cur;
        }
        
        return root;
    }
};

/*
Runtime: 16 ms, faster than 97.61% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13.6 MB, less than 39.66% of C++ online submissions for Merge k Sorted Lists.
*/
