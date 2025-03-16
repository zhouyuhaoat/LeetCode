/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 10:01:53
 *   modified:  2025-03-15 23:14:22
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
    void gotoLeftmostLeaf(TreeNode* root, stack<TreeNode*>& stk) {
        // not emplace root itself
        while (root) {
            if (root->left) { // as left as possible
                if (root->right) { // for access right child directly from left child
                    stk.emplace(root->right);
                }
                stk.emplace(root->left);
                root = root->left;
            } else { // only right if necessary
                stk.emplace(root->right);
                root = root->right;
            }
        }
        stk.pop(); // pop the last nullptr
    }
    // check whether 'pre' is a child of 'node'
    // used to determine whether backtracking a node from its child
    // backtrack from right child to root, if no right child, backtrack from left child
    // if no backtrack, just visiting right child from left child in parallel
    bool isChild(TreeNode* pre, TreeNode* node) {
        return pre == node->left || pre == node->right;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root) stk.emplace(root);
        // emplace root itself firstly to avoid empty stack
        // and gotoLeftmostLeaf() will not emplace root itself
        while (!stk.empty()) {
            // here, 'root' acts as previously visited node, and 'stk.top()' is the current node
            if (!isChild(root, stk.top())) { // if no backtrack, go to leftmost leaf
                gotoLeftmostLeaf(stk.top(), stk);
            }
            // backtrack (continuously)
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
        }
        return res;
    }
};
// @lc code=end
