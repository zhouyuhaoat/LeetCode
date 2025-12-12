/*
 *   author:    zhouyuhao
 *   created:   2025-03-08 18:11:59
 *   modified:  2025-03-15 23:03:00
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        const int VISITING = 0, VISITED = 1; // state
        vector<int> res;
        stack<pair<TreeNode *, int>> stk;
        if (root) stk.emplace(root, VISITING);
        while (!stk.empty()) {
            auto [node, state] = stk.top();
            stk.pop();
            if (!node) continue;
            if (state == VISITING) {
                // preorder in stack: right, left, root
                stk.emplace(node->right, VISITING);
                stk.emplace(node->left, VISITING);
                stk.emplace(node, VISITED);
            } else {
                res.emplace_back(node->val);
            }
        }
        return res;
    }
};
// @lc code=end
