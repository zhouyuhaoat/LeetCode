/*
 *   author:    zhouyuhao
 *   created:   2025-03-06 22:34:41
 *   modified:  2025-03-15 23:16:21
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
        TreeNode *pred = nullptr;
        while (root || !stk.empty()) {
            while (root) { // leftmost vine
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            if (root->right && root->right != pred) {
                root = root->right;
            } else {
                res.emplace_back(root->val);
                pred = root, root = nullptr;
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end
