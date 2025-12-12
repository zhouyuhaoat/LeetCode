/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 09:36:52
 *   modified:  2025-03-07 22:35:34
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
class Solution {
private:
    void goAlongVine(TreeNode *root, stack<TreeNode *>& stk) {
        while (root) {
            stk.emplace(root);
            root = root->left;
        }
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while (true) {
            goAlongVine(root, stk); // glAlongVine -> leftmost vine
            if (stk.empty()) break;
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val); // inorder: visit root after left child, before left child
            root = root->right;
        }
        return res;
    }
};
// @lc code=end
