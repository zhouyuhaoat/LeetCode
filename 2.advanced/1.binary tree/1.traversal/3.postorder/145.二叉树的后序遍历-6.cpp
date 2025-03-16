/*
 *   author:    zhouyuhao
 *   created:   2025-03-06 22:40:39
 *   modified:  2025-03-15 23:20:22
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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        // record the last visited node, use to judge right child visited or not
        // since visit root after left child and right child in postorder
        while (root || !stk.empty()) {
            if (root) {
                stk.emplace(root); // emplace root itself
                // so don't need to emplace root itself firstly to avoid empty stack
                root = root->left; // as left as possible
            } else {
                root = stk.top();
                if (root->right && root->right != pre) { // right exist and not visited
                    root = root->right; // only right if necessary
                } else { // !root->right || root->right == pre
                    // right not exist or visited, left and right all done
                    // backtracked to the root, and visit it
                    // postorder: visit root after left child and right child
                    res.emplace_back(root->val);
                    pre = root;
                    stk.pop();
                    root = nullptr; // for backtrack continuously
                }
            }
        }
        return res;
    }
};
// @lc code=end
