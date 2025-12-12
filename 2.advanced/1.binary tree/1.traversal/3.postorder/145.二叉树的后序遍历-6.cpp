/*
 *   author:    zhouyuhao
 *   created:   2025-03-06 22:34:41
 *   modified:  2025-03-09 13:16:52
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
private:
    void leftmostVine(TreeNode *root, stack<TreeNode *>& stk) {
        while (root) {
            stk.emplace(root);
            root = root->left;
        }
    }

public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *pred = nullptr;
        while (root || !stk.empty()) {
            leftmostVine(root, stk);
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
