/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 10:01:53
 *   modified:  2025-03-08 10:19:46
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
    void gotoLeftmostLeaf(stack<TreeNode*>& stk) {
        while (TreeNode* root = stk.top()) {
            if (root->left) {
                if (root->right) stk.emplace(root->right);
                stk.emplace(root->left);
            } else {
                stk.emplace(root->right);
            }
        }
        stk.pop();
    }
    bool isChild(TreeNode* pre, TreeNode* node) {
        return pre == node->left || pre == node->right;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            if (!isChild(root, stk.top())) {
                gotoLeftmostLeaf(stk);
            }
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
        }
        return res;
    }
};
// @lc code=end
