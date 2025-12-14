/*
 *   author:    zhouyuhao
 *   created:   2024-12-21 16:56:15
 *   modified:  2025-12-13 15:20:29
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
    TreeNode *predecessor(TreeNode *root) {
        TreeNode *pred = root->left;
        while (pred->right) {
            pred = pred->right;
        }
        return pred;
    }

public:
    void flatten(TreeNode *root) {
        if (!root) return;
        if (root->left) {
            TreeNode *pred = predecessor(root);
            pred->right = root->right;
            root->right = root->left, root->left = nullptr;
        }
        flatten(root->right);
    }
};
// @lc code=end
