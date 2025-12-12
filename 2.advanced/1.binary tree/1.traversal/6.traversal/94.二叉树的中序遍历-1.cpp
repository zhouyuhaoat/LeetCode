/*
 *   author:    zhouyuhao
 *   created:   2025-03-08 18:10:28
 *   modified:  2025-03-15 23:07:33
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
public:
    vector<int> inorderTraversal(TreeNode *root) {
        const int VISITING = 0, VISITED = 1; // state
        vector<int> res;
        stack<pair<TreeNode *, int>> stk;
        if (root) stk.emplace(root, VISITING);
        while (!stk.empty()) {
            auto [node, state] = stk.top();
            stk.pop();
            if (!node) continue;
            if (state == VISITING) {
                // inorder in stack: right, root, left
                stk.emplace(node->right, VISITING);
                stk.emplace(node, VISITED);
                stk.emplace(node->left, VISITING);
            } else {
                res.emplace_back(node->val);
            }
        }
        return res;
    }
};
// @lc code=end
