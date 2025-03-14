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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) { // Morris Traversal: threading
        vector<int> res;
        while (root) {
            if (root->left) {
                TreeNode* pre = root->left;
                // predecessor of the root: left child's rightest child, include the left child itself
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    // first time visit the predecessor when first time visit the root: create temporary link
                    pre->right = root; // unused right pointer of predecessor
                    res.emplace_back(root->val); // preorder: visit root before left child
                    root = root->left;
                } else {
                    // second time visit the predecessor after backtrack to the root: remove temporary link
                    pre->right = nullptr; // recover the right pointer of predecessor
                    root = root->right;
                }
            } else {
                res.emplace_back(root->val);
                // preorder: visit root before right child if no backtrack
                // preorder: visit left child before right child if backtrack
                root = root->right; // backtrack to ancestor without explicit stack trace
                // if the root has a right child originally, the right child will be visited after the root
                // if the root has no right child originally, it is a leaf, also a predecessor of a ancestor
                // so the ancestor will be visited by backtracking through the temporary link
                // and the temporary link will be removed, the ancestor's right child will be visited
            }
        } // ended with the rightest child of the root, it's right child is nullptr
        return res;
    }
};
// @lc code=end
