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
class Solution {
private:
    TreeNode *predecessor(TreeNode *root) {
        TreeNode *pred = root->left;
        while (pred->right && pred->right != root) {
            pred = pred->right;
        }
        return pred;
    }

    void visitAlongRightmostVine(TreeNode *root, vector<int>& res) {
        int len = 0;
        while (root) {
            res.emplace_back(root->val);
            root = root->right;
            len++;
        }
        reverse(res.end() - len, res.end());
    }

public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *temp = root;
        while (root) {
            if (root->left) {
                TreeNode *pred = predecessor(root);
                if (!pred->right) {
                    pred->right = root;
                    root = root->left;
                } else {
                    pred->right = nullptr;
                    /*
                        postorder
                        - visit the rightmost vine of the left subtree
                        - after the left subtree is done and backtrack to the root
                     */
                    visitAlongRightmostVine(root->left, res);
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        visitAlongRightmostVine(temp, res); // the rightmost vine of the tree
        return res;
    }
};
// @lc code=end
