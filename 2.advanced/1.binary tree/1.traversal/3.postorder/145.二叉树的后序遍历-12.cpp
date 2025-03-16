/*
 *   author:    zhouyuhao
 *   created:   2025-03-08 18:13:06
 *   modified:  2025-03-15 23:23:38
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
        // UNVISITED -> VISITING -> VISITED
        // VISITING: first time push onto stack
        // VISITED: second time push onto stack
        // push onto stack twice, also pop from stack twice
        const int VISITING = 0, VISITED = 1;
        vector<int> res;
        stack<pair<TreeNode*, int>> stk;
        if (root) stk.emplace(root, VISITING);
        // VISITING: push the subtree rooted at the node onto stack
        while (!stk.empty()) {
            auto [node, state] = stk.top();
            stk.pop();
            if (!node) continue;
            if (state == VISITING) { // first time pop from stack
                // enfold the tree into subtrees and root
                // postorder in stack: root, right, left
                stk.emplace(node, VISITED);
                stk.emplace(node->right, VISITING);
                stk.emplace(node->left, VISITING);
                // VISITED: push the node onto stack
            } else { // second time pop from stack
                // traverse the node after enfolded
                res.emplace_back(node->val);
            }
        }
        return res;
    }
};
// @lc code=end
