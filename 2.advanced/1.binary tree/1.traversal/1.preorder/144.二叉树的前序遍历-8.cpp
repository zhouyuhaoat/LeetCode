/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 12:26:48
 *   modified:  2025-03-07 22:32:17
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
            res.emplace_back(root->val);
            root = root->left;
        }
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            visitAlongVine(root, stk, res);
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return res;
    }
};
// @lc code=end
