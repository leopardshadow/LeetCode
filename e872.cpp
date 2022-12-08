
// 2022.12.8

/*
leetcode 改版後好醜喔，以後就不放贏過多少了，不能直接複製...
*/

class Solution {
    vector<int> a, b;
    void genSeq(TreeNode* node, vector<int> &vec) {
        if (!node)
            return;
        genSeq(node->left, vec);
        if (!node->right && !node->left)
            vec.push_back(node->val);
        genSeq(node->right, vec);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        genSeq(root1, a);
        genSeq(root2, b);
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
};
