
// 12.29

//******************************************************************************//
// 12.29 - Just Before A VO

/*
這題一臉就寫著：我是 BFS
*/

class Solution {
public:
    Node* connect(Node* root) {
        list<Node*> q;
        
        if(root)
            q.push_back(root);
        else
            return NULL;
        
        while(!q.empty()) {
            int len = q.size();
            Node *curr;
            for(int i = 0; i < len; i++) {
                curr = q.front();
                q.pop_front();
                
                if(q.size())
                    curr->next = q.front();
                
                if(curr->left)
                    q.push_back(curr->left);
                if(curr->right)
                    q.push_back(curr->right);
            }
            curr->next = NULL;
        }
        return root;
    }
};

/*
Runtime: 32 ms, faster than 7.98% of C++ online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 18.4 MB, less than 5.73% of C++ online submissions for Populating Next Right Pointers in Each Node.
*/
