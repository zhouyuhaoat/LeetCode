/*
 *   author:    zhouyuhao
 *   created:   2025-03-06 22:40:39
 *   modified:  2025-03-15 23:20:22
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *pred = nullptr; // predecessor
        while (root || !stk.empty()) {
            if (root) {
                stk.emplace(root);
                root = root->left;
            } else {
                root = stk.top();
                if (root->right && root->right != pred) {
                    root = root->right;
                } else {
                    res.emplace_back(root->val); // postorder: visit root after left child and right child
                    pred = root, root = nullptr;
                    stk.pop();
                }
            }
        }
        return res;
    }
};
// @lc code=end
