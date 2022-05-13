
// 2022.5.13

/*
一開始我居然把 next 和 right 搞錯 ...
箭頭畫的是 ->，但那是 next
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    
    map<int, vector<Node*>> layers;
    
    void traverse(Node* node, int depth) {
        
        if (!node)
            return;
        
        layers[depth].push_back(node);
        
        traverse(node->left, depth + 1);
        traverse(node->right, depth + 1);
    }
    
public:
    Node* connect(Node* root) {
        
        //
        traverse(root, 0);
        
        //
        for (auto &[d, layer] : layers) {
            for (int i = 1; i < layer.size(); i++) {
                layer[i-1]->next= layer[i];
            }
                
            layer.back()->next = NULL;
        }
        
        return root;
    }
};
/*
Runtime: 18 ms, faster than 54.04% of C++ online submissions for Populating Next Right Pointers in Each Node II.
Memory Usage: 18.2 MB, less than 5.89% of C++ online submissions for Populating Next Right Pointers in Each Node II.
*/
