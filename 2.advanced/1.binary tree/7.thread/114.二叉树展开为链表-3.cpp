/*
 *   author:    zhouyuhao
 *   created:   2024-12-22 20:12:11
 *   modified:  2025-12-13 23:01:26
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
class Solution {
private:
    void preorder(TreeNode *root) {
        stack<TreeNode *> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            if (root->right) stk.emplace(root->right);
            if (root->left) stk.emplace(root->left);
            root->left = nullptr, root->right = stk.empty() ? nullptr : stk.top(); // successor
        }
    }

public:
    void flatten(TreeNode *root) {
        preorder(root);
    }
};
// @lc code=end
