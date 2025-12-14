/*
 *   author:    zhouyuhao
 *   created:   2025-12-13 19:43:30
 *   modified:  2025-12-14 09:39:56
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
    TreeNode dummy, *tail = &dummy;

    TreeNode *predecessor(TreeNode *root) {
        TreeNode *pred = root->left;
        while (pred->right && pred->right != root) {
            pred = pred->right;
        }
        return pred;
    }

    void inorder(TreeNode *root) {
        while (root) {
            if (root->left) {
                TreeNode *pred = predecessor(root);
                if (!pred->right) {
                    pred->right = root;
                    root = root->left;
                } else {
                    pred->right = nullptr;
                    tail = tail->right = root;
                    root->left = nullptr; // cut
                    root = root->right;
                }
            } else {
                tail = tail->right = root; // connect
                root = root->right;
            }
        }
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        inorder(root);
        return dummy.right;
    }
};
// @lc code=end
