/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 12:26:48
 *   modified:  2025-03-07 23:16:09
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
private:
    void visitAlongVine(TreeNode* root, stack<TreeNode*>& stk, vector<int>& res) {
        while (root) {
            stk.emplace(root);
            res.emplace_back(root->val);
            root = root->left;
        }
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root) stk.emplace(root); // root is visited twice
        // before the second visit, visit the rightmost node, and it's right child is nullptr
        // so when the second visit happens, the root is nullptr, and don't visitAlongVine, just pop
        // and because 'res' is update only in visitAlongVine, so the result is not changed
        // not subject to the inorder traversal, since it update the 'res' outside goAlongVine
        while (!stk.empty()) {
            visitAlongVine(root, stk, res);
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};
// @lc code=end
