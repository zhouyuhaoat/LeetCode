/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 12:35:44
 *   modified:  2025-03-07 12:36:16
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
private:
    void goAlongVine(TreeNode *root, stack<TreeNode *>& stk) {
        while (root) {
            stk.emplace(root);
            root = root->left;
        }
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            goAlongVine(root, stk);
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
            root = root->right;
        }
        return res;
    }
};
// @lc code=end
