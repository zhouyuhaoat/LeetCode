/*
 *   author:    zhouyuhao
 *   created:   2024-12-18 19:54:54
 *   modified:  2025-03-09 10:18:50
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
class Solution {
private:
    TreeNode *predecessor(TreeNode *root) {
        TreeNode *pred = root->left;
        while (pred->right && pred->right != root) {
            pred = pred->right;
        }
        return pred;
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        while (root) {
            if (root->left) {
                TreeNode *pred = predecessor(root);
                if (!pred->right) {
                    pred->right = root;
                    res.emplace_back(root->val); // preorder: visit root before left child
                    root = root->left;
                } else {
                    pred->right = nullptr;
                    root = root->right;
                }
            } else {
                /*
                    preorder
                    1. visit root before right child if no backtrack
                    2. visit predecessor in the left subtree after root if backtrack
                 */
                res.emplace_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end
