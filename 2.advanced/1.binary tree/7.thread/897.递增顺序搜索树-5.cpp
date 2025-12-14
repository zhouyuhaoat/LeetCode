/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 18:26:07
 *   modified:  2025-12-13 23:43:48
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode *increasingBST(TreeNode *root) {
        if (!root) return nullptr;
        TreeNode *left = increasingBST(root->left);
        root->right = increasingBST(root->right);
        if (root->left) {
            TreeNode *pred = predecessor(root);
            pred->right = root; // connect
            root->left = nullptr; // cut
            root = left;
        }
        return root;
    }
};
// @lc code=end
