/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 12:13:09
 *   modified:  2025-03-15 23:06:00
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
        vector<int> res;
        stack<TreeNode *> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            if (root) {
                if (root->right) stk.emplace(root->right);
                stk.emplace(root), stk.emplace(nullptr); // marker
                if (root->left) stk.emplace(root->left);
            } else {
                res.emplace_back(stk.top()->val);
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end
