/*
 *   author:    zhouyuhao
 *   created:   2024-12-18 19:47:40
 *   modified:  2025-03-07 22:31:37
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
private:
    void visitAlongVine(TreeNode *root, stack<TreeNode *>& stk, vector<int>& res) {
        while (root) {
            stk.emplace(root);
            res.emplace_back(root->val); // preorder: visit root before left child
            root = root->left;
        }
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while (true) {
            visitAlongVine(root, stk, res); // visitAlongVine -> leftmost vine
            if (stk.empty()) break;
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};
// @lc code=end
