
// 2022.4.20

/*
tree in-order traversal 的 iterative 寫法～
*/

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {  // in-order traversal

        TreeNode *retNode = st.top();
        st.pop();
        
        //
        TreeNode *node = retNode->right;
        while(node) {
            st.push(node);
            node = node->left;
        }
                
        return retNode->val;
    }
    
    bool hasNext() {
        return st.size();
    }
};
/*
Runtime: 24 ms, faster than 95.32% of C++ online submissions for Binary Search Tree Iterator.
Memory Usage: 24 MB, less than 98.10% of C++ online submissions for Binary Search Tree Iterator.
*/
