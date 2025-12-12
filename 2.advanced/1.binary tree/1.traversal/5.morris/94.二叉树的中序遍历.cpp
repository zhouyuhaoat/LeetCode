/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 09:52:45
 *   modified:  2025-03-09 10:30:09
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
    TreeNode *predecessor(TreeNode *root) {
        TreeNode *pred = root->left;
        while (pred->right && pred->right != root) {
            pred = pred->right;
        }
        return pred;
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        while (root) {
            if (root->left) {
                TreeNode *pred = predecessor(root);
                if (!pred->right) {
                    pred->right = root;
                    root = root->left;
                } else {
                    pred->right = nullptr;
                    res.emplace_back(root->val); // inorder: visit root after left child, before right child
                    root = root->right;
                }
            } else {
                /*
                    inorder
                    - visit root before right child if no backtrack
                    - visit predecessor in the left subtree before root if backtrack
                 */
                res.emplace_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end
