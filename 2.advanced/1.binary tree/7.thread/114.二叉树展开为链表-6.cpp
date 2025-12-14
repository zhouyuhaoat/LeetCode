/*
 *   author:    zhouyuhao
 *   created:   2024-12-22 20:07:24
 *   modified:  2025-12-13 15:16:53
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
        while (root) {
            if (root->left) {
                TreeNode *pred = predecessor(root);
                pred->right = root->right;
                root->right = root->left, root->left = nullptr;
            }
            root = root->right;
        }
    }
};
// @lc code=end
