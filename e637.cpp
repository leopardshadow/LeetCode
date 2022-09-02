
// 2022.9.2

/*
因為算平均最後都是混在一起，所以 traverse 方式不管是哪一種 order 都沒差～
*/

class Solution {
    vector<pair<double, int>> sum;
    void traverse(TreeNode* root, int level) {
        if (!root)
            return;
        if (sum.size() <= level)
            sum.push_back({0, 0});
        sum[level].first += root->val;
        sum[level].second++;
        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        traverse(root, 0);
            
        vector<double> ans;
        for (auto &p : sum)
            ans.push_back(p.first / p.second);
        return ans;
    }
};
/*
Runtime: 23 ms, faster than 62.00% of C++ online submissions for Average of Levels in Binary Tree.
Memory Usage: 22.6 MB, less than 19.66% of C++ online submissions for Average of Levels in Binary Tree.
*/
