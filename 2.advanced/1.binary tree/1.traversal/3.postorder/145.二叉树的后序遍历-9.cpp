/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 10:38:47
 *   modified:  2025-03-09 13:28:50
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
private:
    void addPath(TreeNode* root, vector<int>& res) {
        int cnt = 0;
        while (root) {
            res.emplace_back(root->val);
            root = root->right; // the right path to the rightest child
            cnt++;
        }
        reverse(res.end() - cnt, res.end());
        // no left => preorder or inorder: root, right
        // reverse => postorder: right, root
    }

public:
    vector<int> postorderTraversal(TreeNode* root) { // Morris Traversal: threading
        vector<int> res;
        TreeNode* top = root;
        while (root) {
            if (root->left) {
                // predecessor of the root: left child's rightest child, include the left child itself
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    // first time visit the predecessor when first time visit the root: create temporary link
                    pre->right = root; // unused right pointer of predecessor
                    root = root->left;
                } else {
                    // second time visit the predecessor after backtrack to the root: remove temporary link
                    pre->right = nullptr; // recover the right pointer of predecessor
                    addPath(root->left, res); // visit the right path of the left subtree after backtrack to the root
                    root = root->right;
                }
            } else {
                root = root->right; // backtrack to ancestor without explicit stack trace
                // if the root has a right child originally, the right child will be visited after the root
                // if the root has no right child originally, it is a leaf, also a predecessor of a ancestor
                // so the ancestor will be visited by backtracking through the temporary link
                // and the temporary link will be removed, the ancestor's right child will be visited
            }
        } // ended with the rightest child of the root, it's right child is nullptr
        addPath(top, res); // visit the right path of the root
        return res;
    }
};
// @lc code=end
