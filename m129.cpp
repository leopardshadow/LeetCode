/*
2021.11.3 Daily 但那時候才剛面完，不想寫 daily，剛好最近在寫 tree 的題目就把他做掉了
*/

/*
自己想的 follow-up
如果數字變反過來 1 -> 2 -> 3 在這題表示的是 123，如果要 321 怎麼改
也許可以多傳深度資訊
*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    int sumNumbers(TreeNode* root, int curNum) {
        if(!root->left && !root->right)
            return 10 * curNum + root->val;
        int leftnum = 0, rightnum = 0;
        if(root->left)
            leftnum = sumNumbers(root->left, 10 * curNum + root->val);
        if(root->right)
            rightnum = sumNumbers(root->right, 10 * curNum + root->val);
        return leftnum + rightnum;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum Root to Leaf Numbers.
Memory Usage: 9.3 MB, less than 13.52% of C++ online submissions for Sum Root to Leaf Numbers.
*/
