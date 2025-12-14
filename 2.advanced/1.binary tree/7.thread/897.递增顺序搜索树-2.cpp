/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 18:15:32
 *   modified:  2025-12-14 09:35:30
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
    TreeNode dummy, *tail = &dummy; // tail insertion

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        tail = tail->right = root; // connect
        root->left = nullptr; // cut
        inorder(root->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        inorder(root);
        return dummy.right;
    }
};
// @lc code=end
